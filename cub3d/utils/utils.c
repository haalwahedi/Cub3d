/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:43:33 by hamdas            #+#    #+#             */
/*   Updated: 2023/01/10 12:59:52 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// check if the raycast hit the offset on the x axis (vertical)
void	offset_inverse(t_ray ray, int *offset_texture_x)
{
	if (ray.was_hit_vertical == 1
		&& is_ray_facing_down(ray.ray_angle) == 0)
		*offset_texture_x = TILE - *offset_texture_x;
	if (ray.was_hit_vertical == 0
		&& is_ray_facing_left(ray.ray_angle) == 0)
		*offset_texture_x = TILE - *offset_texture_x;
}

// this function is to normalize the angle of the ray
float	normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

// using the quadratic formula to calculate distance brtween points
float	distance_inbetween(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) *(y2 - y1)));
}
