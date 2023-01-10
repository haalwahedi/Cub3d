/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:55:23 by hamdas            #+#    #+#             */
/*   Updated: 2023/01/10 12:23:53 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// we previoulsy created a buffer to store the 
// perpendicular distance of the vertical 
// stripes to raycast the walls,  
// now we create a 3D projection by assigning values to: 
//  - the perpindicular distance - 
//  to calculate the sprite size in x & y directions
//  - the ray angle - to identify the direction or path of the ray
//  - the angles for rays & players rotation, to help movement 
//   - the projection plane distance - 
//   to projet the 3D objects on the 2D window surface
//   - the wall height top to bottom - 
//  to drawing vertical stripes pixel by pixel */

void	get_values_projection(t_cub3d *cub, t_projection *var)
{
	var->perp_dist = cub->rays[var->x].distance
		* cos(cub->rays[var->x].ray_angle - cub->player.rotation_angle);
	var->proj_wall_height = (TILE / var->perp_dist)
		* cub->dist_proj_plane;
	var->wall_strip_height = (int)var->proj_wall_height;
	var->wall_top_pixel = (HEIGHT / 2) - (var->wall_strip_height / 2);
	if (var->wall_top_pixel < 0)
		var->wall_top_pixel = 0;
	if (var->wall_top_pixel >= HEIGHT)
		var->wall_top_pixel = HEIGHT;
	var->wall_bottom_pixel = (HEIGHT / 2) + (var->wall_strip_height / 2);
	if (var->wall_bottom_pixel >= HEIGHT)
		var->wall_bottom_pixel = HEIGHT;
	if (var->wall_bottom_pixel < 0)
		var->wall_bottom_pixel = 0;
}

// using mlx to draw the ceiling and floor pixel by pixel
void	draw_ceiling(t_cub3d *cub, t_projection var)
{
	var.y = 0;
	while (var.y < var.wall_top_pixel)
		ft_mlx_pixel_put(&cub->img, var.x, var.y++, cub->collors.cell);
}

void	draw_floor(t_cub3d *cub, t_projection var)
{
	var.y = var.wall_bottom_pixel;
	while (var.y < HEIGHT)
		ft_mlx_pixel_put(&cub->img, var.x, var.y++, cub->collors.floor);
}

// checking offset texture and the ray angle if 
// the ray hits offset before projection
void	get_texture_offset(t_cub3d *cub, t_projection *var)
{
	if (cub->rays[var->x].was_hit_vertical == 0)
		var->texture_offset_x = (int)cub->rays[var->x].wall_hit_y % TILE;
	else
		var->texture_offset_x = (int)cub->rays[var->x].wall_hit_x % TILE;
	offset_inverse(cub->rays[var->x], &var->texture_offset_x);
	var->tex_num = cub->rays[var->x].wall_hit_cotent;
}

// generating the 3D projection once all values are obtained
void	generate3d_projection(t_cub3d *cub)
{
	t_projection	var;

	ft_bzero(&var, sizeof(t_projection));
	while (var.x < NUM_RAYS)
	{
		get_values_projection(cub, &var);
		draw_ceiling(cub, var);
		get_texture_offset(cub, &var);
		var.y = var.wall_top_pixel;
		while (var.y < var.wall_bottom_pixel)
		{
			var.distance_from_top = var.y + (var.wall_strip_height / 2)
				- (HEIGHT / 2);
			var.texture_off_sety = var.distance_from_top
				* ((float)TEXTURE_HEIGHT / var.wall_strip_height);
			var.texel_color = cub->textures[var.tex_num][(TEXTURE_WIDTH
					* var.texture_off_sety) + var.texture_offset_x];
			if (cub->rays[var.x].was_hit_vertical == 0)
				change_color_intesity(&var.texel_color, 0.7);
			ft_mlx_pixel_put(&cub->img, var.x, var.y, var.texel_color);
			var.y++;
		}
		draw_floor(cub, var);
		var.x++;
	}
}
