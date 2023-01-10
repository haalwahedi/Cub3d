/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sides.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:43:23 by hamdas            #+#    #+#             */
/*   Updated: 2023/01/10 12:58:37 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* These functions are used to identify the 
** direction of the ray by checking the angle */
int	is_ray_facing_down(float angle)
{
	if (angle > 0 && angle < PI)
		return (0);
	else
		return (1);
}

int	is_ray_racing_up(float angle)
{
	if (is_ray_facing_down(angle) == 0)
		return (1);
	else
		return (0);
}

int	is_ray_facing_right(float angle)
{
	if (angle < 0.5 * PI || angle > 1.5 * PI)
		return (0);
	else
		return (1);
}

int	is_ray_facing_left(float angle)
{
	if (is_ray_facing_right(angle) == 0)
		return (1);
	else
		return (0);
}
