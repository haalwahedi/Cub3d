/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:25:45 by hamdas            #+#    #+#             */
/*   Updated: 2023/01/10 12:24:59 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// calculating the distance of the ray by inserting 
// points in the quadratic formula used in distance inbetween function 
void	get_ray_distance(t_cub3d *cub, t_aux_ray *horz, t_aux_ray *vert)
{
	if (horz->found_wall_hit == 0)
		horz->hit_distance = distance_inbetween(
				cub->player.x, cub->player.y, horz->wall_hit_x,
				horz->wall_hit_y);
	else
		horz->hit_distance = INT_MAX;
	if (vert->found_wall_hit == 0)
		vert->hit_distance = distance_inbetween(
				cub->player.x, cub->player.y, vert->wall_hit_x,
				vert->wall_hit_y);
	else
		vert->hit_distance = INT_MAX;
}

// assigning value for the ray referring back to the 
// distance between the ray and another object
void	get_values_of_ray(t_ray *ray, t_utils_ray utils,
	t_aux_ray horz, t_aux_ray vert)
{
	if (vert.hit_distance < horz.hit_distance)
	{
		ray->distance = vert.hit_distance;
		ray->wall_hit_x = vert.wall_hit_x;
		ray->wall_hit_y = vert.wall_hit_y;
		ray->wall_hit_cotent = vert.wall_content;
		if (utils.is_ray_facing_left == 0)
			ray->wall_hit_cotent = WE;
		else
			ray->wall_hit_cotent = EA;
		ray->was_hit_vertical = 0;
	}
	else
	{
		ray->distance = horz.hit_distance;
		ray->wall_hit_x = horz.wall_hit_x;
		ray->wall_hit_y = horz.wall_hit_y;
		ray->wall_hit_cotent = horz.wall_content;
		if (utils.is_ray_facing_up == 0)
			ray->wall_hit_cotent = NO;
		else
			ray->wall_hit_cotent = SO;
		ray->was_hit_vertical = 1;
	}
}

// casting the ray with respect to the angle it is positioned at
void	cast_ray(float ray_angle, int id, t_cub3d *cub)
{
	t_utils_ray	utils;
	t_aux_ray	horz;
	t_aux_ray	vert;

	ft_bzero(&utils, sizeof(t_utils_ray));
	ft_bzero(&cub->rays[id], sizeof(t_ray));
	ray_angle = normalize_angle(ray_angle);
	utils.is_ray_facing_down = is_ray_facing_down(ray_angle);
	utils.is_ray_facing_up = is_ray_racing_up(ray_angle);
	utils.is_ray_facing_right = is_ray_facing_right(ray_angle);
	utils.is_ray_facing_left = is_ray_facing_left(ray_angle);
	horz = ray_horizontal(cub, &utils, ray_angle);
	vert = ray_vertical(cub, &utils, ray_angle);
	get_ray_distance(cub, &horz, &vert);
	get_values_of_ray(&cub->rays[id], utils, horz, vert);
	cub->rays[id].ray_angle = ray_angle;
}

// casting all rays on a calculated angle that takes 
// players rotation angle & projection plane distance into consideration 
void	cast_all_rays(t_cub3d *cub)
{
	float	ray_angle;
	int		col;

	col = 0;
	while (col < NUM_RAYS)
	{
		ray_angle = cub->player.rotation_angle + atan((col - NUM_RAYS / 2)
				/ cub->dist_proj_plane);
		cast_ray(ray_angle, col, cub);
		col++;
	}
}
