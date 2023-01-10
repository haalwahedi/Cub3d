/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:43:28 by hamdas            #+#    #+#             */
/*   Updated: 2023/01/10 12:58:42 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Selecting the keys for the players movements
static void	player_orientation(t_cub3d *cub, char c)
{
	if (c == 'N')
		cub->player.orientation = NO;
	else if (c == 'S')
		cub->player.orientation = SO;
	else if (c == 'W')
		cub->player.orientation = WE;
	else if (c == 'E')
		cub->player.orientation = EA;
}

// locating the player's position on the map
static void	player_position(t_cub3d *cub)
{
	int		x;
	size_t	y;

	x = 0;
	while (x < cub->map_info.height)
	{
		y = 0;
		while (y < ft_strlen(cub->map[x]))
		{
			if (cub->map[x][y] == 'N' || cub->map[x][y] == 'S' ||
				cub->map[x][y] == 'W' || cub->map[x][y] == 'E')
			{
				cub->player.x = (y * TILE) + 31;
				cub->player.y = (x * TILE) + 32;
				player_orientation(cub, cub->map[x][y]);
				cub->map[x][y] = '0';
				break ;
			}
			y++;
		}
		if (cub->player.x != 0)
			break ;
		x++;
	}
}

// finding the initial angle of the player in the game
static void	save_initial_angle(t_cub3d *cub)
{
	if (cub->player.orientation == WE)
		cub->player.rotation_angle = TWO_PI / 2;
	else if (cub->player.orientation == EA)
		cub->player.rotation_angle = (TWO_PI * 2) / 2;
	else if (cub->player.orientation == SO)
		cub->player.rotation_angle = PI / 2;
	else if (cub->player.orientation == NO)
		cub->player.rotation_angle = (PI * 3) / 2;
}

// choosing the default settings for the player  to start
static void	start_player(t_cub3d *cub)
{
	ft_bzero(&cub->player, sizeof(t_player));
	cub->map_info.height = ft_strlen_split(cub->map);
	player_position(cub);
	cub->player.width = 5;
	cub->player.height = 5;
	cub->player.turn_direction = 0;
	cub->player.walk_direction = 0;
	save_initial_angle(cub);
	cub->player.walk_speed = 10;
	cub->player.turn_speed = 2 * (PI / 180);
}

// setting the player's texture, images, and  mlx colors
void	setup(t_cub3d *cub)
{
	double	fov;

	fov = 60 * (PI / 180);
	cub->dist_proj_plane = ((WIDTH / 2) / tan(fov / 2));
	start_player(cub);
	start_textures(cub);
	free_images(cub);
	cub->collors.cell = get_color_mlx(cub->collors.cell_rgb);
	cub->collors.floor = get_color_mlx(cub->collors.floor_rgb);
}
