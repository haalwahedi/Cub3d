/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:25:21 by mal-hadr          #+#    #+#             */
/*   Updated: 2023/01/10 12:25:24 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_player(t_cub3d *cub)
{
	float	move_step;
	float	side_step;
	float	newx;
	float	newy;

	cub->player.rotation_angle += cub->player.turn_direction
		* cub->player.turn_speed;
	side_step = cub->player.side_direction * cub->player.walk_speed;
	move_step = cub->player.walk_direction * cub->player.walk_speed;
	if (move_step && side_step)
	{
		move_step /= 2;
		side_step /= 2;
	}
	newx = cub->player.x + cos(cub->player.rotation_angle) * move_step;
	newy = cub->player.y + sin(cub->player.rotation_angle) * move_step;
	newx = newx - sin(-cub->player.rotation_angle) * side_step;
	newy = newy - cos(-cub->player.rotation_angle) * side_step;
	if (!map_has_wall_at(cub, newx, newy))
	{
		cub->player.x = newx;
		cub->player.y = newy;
	}
}

void	update(t_cub3d *cub)
{
	move_player(cub);
	cast_all_rays(cub);
}

int	action_loop(t_cub3d *cub)
{
	update(cub);
	draw_gaming(cub);
	return (1);
}

int	action(int keycode, t_cub3d *cub)
{
	if (keycode == ESC)
		close_win(cub);
	if (keycode == RIGHT)
		cub->player.side_direction = -1;
	if (keycode == ARROW_RIGHT)
		cub->player.turn_direction = +1;
	if (keycode == LEFT)
		cub->player.side_direction = +1;
	if (keycode == ARROW_LEFT)
		cub->player.turn_direction = -1;
	if (keycode == TOP)
		cub->player.walk_direction = +1;
	if (keycode == DOWN)
		cub->player.walk_direction = -1;
	return (0);
}
