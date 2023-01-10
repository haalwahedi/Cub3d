/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utlis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:58:22 by mal-hadr          #+#    #+#             */
/*   Updated: 2023/01/10 12:58:28 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* these functions are meant to setup the map for the game
** checking size of the map and if the player is within the map
** checking if the map has walls compatible with the floor size
** setting the floor line on the map of choice */

int	is_inside_map(float x, float y, t_cub3d *cub)
{
	if (x >= 0 && x <= get_lenght(cub, y) * TILE && y >= 0
		&& y <= cub->map_info.height * TILE)
		return (0);
	else
		return (1);
}

int	map_has_wall_at(t_cub3d *cub, float x, float y)
{
	int	map_grid_indexx;
	int	map_grid_indexy;

	if (x < 0 || x >= get_lenght(cub, y) * TILE || y < 0
		|| y >= cub->map_info.height * TILE)
		return (1);
	map_grid_indexx = floor(x / TILE);
	map_grid_indexy = floor(y / TILE);
	return (cub->map[map_grid_indexy][map_grid_indexx] != '0');
}

int	get_lenght(t_cub3d *cub, float line)
{
	if ((int)floor(line / TILE) < 0 || (int)floor(line / TILE)
		> cub->map_info.height)
		return (0);
	else
		return ((int)ft_strlen(cub->map[(int)floor(line / TILE)]));
}
