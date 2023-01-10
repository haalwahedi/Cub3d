/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:30:28 by hamdas            #+#    #+#             */
/*   Updated: 2023/01/10 12:24:37 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// identifying the horizontal intersection using auxiliary 
// variable to help computing estimates of the y and x intercepts

void	find_horz_intersection(t_aux_ray *aux, t_utils_ray *utils, t_cub3d *cub)
{
	aux->next_touchx = utils->x_intercept;
	aux->next_touchy = utils->y_intercept;
	while (is_inside_map(aux->next_touchx, aux->next_touchy, cub) == 0)
	{
		aux->xto_check = aux->next_touchx;
		if (utils->is_ray_facing_up == 0)
			aux->yto_check = aux->next_touchy + -1;
		else
			aux->yto_check = aux->next_touchy;
		if (map_has_wall_at(cub, aux->xto_check, aux->yto_check))
		{
			aux->wall_hit_x = aux->next_touchx;
			aux->wall_hit_y = aux->next_touchy;
			aux->wall_content = cub->map[(int)floor(aux->yto_check / TILE)]
			[(int)floor(aux->xto_check / TILE)] - '0';
			aux->found_wall_hit = 0;
			break ;
		}
		else
		{
			aux->next_touchx += utils->x_step;
			aux->next_touchy += utils->y_step;
		}
	}
}

// checking if the ray is casting horizontally with respect 
// to the horizontal intersection calculated in the above function
t_aux_ray	ray_horizontal(t_cub3d *cub, t_utils_ray *utils, float angle)
{
	t_aux_ray	aux;

	ft_bzero(&aux, sizeof(t_aux_ray));
	aux.found_wall_hit = 1;
	utils->y_intercept = floor(cub->player.y / TILE) * TILE;
	if (utils->is_ray_facing_down == 0)
		utils->y_intercept += TILE;
	utils->x_intercept = cub->player.x
		+ (utils->y_intercept - cub->player.y) / tan(angle);
	utils->y_step = TILE;
	if (utils->is_ray_facing_up == 0)
		utils->y_step *= -1;
	utils->x_step = TILE / tan(angle);
	if (utils->is_ray_facing_left == 0 && utils->x_step > 0)
		utils->x_step *= -1;
	if (utils->is_ray_facing_right == 0 && utils->x_step < 0)
		utils->x_step *= -1;
	find_horz_intersection(&aux, utils, cub);
	return (aux);
}

// identifying the vertical intersection using auxiliary 
// variable to help computing estimates of the y and x intercepts
void	find_vert_intersection(t_aux_ray *aux, t_utils_ray *utils, t_cub3d *cub)
{
	aux->next_touchx = utils->x_intercept;
	aux->next_touchy = utils->y_intercept;
	while (is_inside_map(aux->next_touchx, aux->next_touchy, cub) == 0)
	{
		aux->yto_check = aux->next_touchy;
		if (utils->is_ray_facing_left == 0)
			aux->xto_check = aux->next_touchx + -1;
		else
			aux->xto_check = aux->next_touchx;
		if (map_has_wall_at(cub, aux->xto_check, aux->yto_check))
		{
			aux->wall_hit_x = aux->next_touchx;
			aux->wall_hit_y = aux->next_touchy;
			aux->wall_content = cub->map[(int)floor(aux->yto_check / TILE)]
			[(int)floor(aux->xto_check / TILE)] - '0';
			aux->found_wall_hit = 0;
			break ;
		}
		else
		{
			aux->next_touchx += utils->x_step;
			aux->next_touchy += utils->y_step;
		}
	}
}

// checking if the ray is casting vertically with respect 
// to the vertical intersection calculated in the above function
t_aux_ray	ray_vertical(t_cub3d *cub, t_utils_ray *utils, float angle)
{
	t_aux_ray	aux;

	ft_bzero(&aux, sizeof(t_aux_ray));
	aux.found_wall_hit = 1;
	utils->x_intercept = floor(cub->player.x / TILE) * TILE;
	if (utils->is_ray_facing_right == 0)
		utils->x_intercept += TILE;
	utils->y_intercept = cub->player.y
		+ (utils->x_intercept - cub->player.x) * tan(angle);
	utils->x_step = TILE;
	if (utils->is_ray_facing_left == 0)
		utils->x_step *= -1;
	utils->y_step = TILE * tan(angle);
	if (utils->is_ray_facing_up == 0 && utils->y_step > 0)
		utils->y_step *= -1;
	if (utils->is_ray_facing_down == 0 && utils->y_step < 0)
		utils->y_step *= -1;
	find_vert_intersection(&aux, utils, cub);
	return (aux);
}
