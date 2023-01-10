/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:45:11 by mal-hadr          #+#    #+#             */
/*   Updated: 2023/01/10 12:57:50 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	valid_size_map(char **map)
{
	if (ft_strlen_split(map) < 3)
		return (1);
	return (0);
}

//Check if the map file and content is valid.
int	check_map(char *map_path, t_cub3d *cub3d)
{
	cub3d->map_content = remove_empty_line(get_map(map_path));
	if (cub3d->map_content == NULL)
		return (error_msg("MAP EMPTY!", NULL));
	cub3d->colors_cf = valid_ceilling_and_floor_color(cub3d->map_content);
	if (cub3d->colors_cf == NULL)
		return (error_msg("Sky or ground colors isn't exist!", cub3d));
	cub3d->collors = check_color(cub3d->colors_cf);
	if (cub3d->collors.status == 1)
		return (error_msg("Sky or ground colors isn't wrong!", cub3d));
	cub3d->path_texture = valid_texture(cub3d->map_content);
	if (cub3d->path_texture == NULL)
		return (error_msg("Invalid textures!", cub3d));
	if (texture_file_exist(cub3d->path_texture) == 1)
		return (error_msg("Texture files doesn't exist!", cub3d));
	cub3d->map = store_map_blueprint(cub3d->map_content);
	if (valid_size_map(cub3d->map) == 1)
		return (error_msg("The size map is invalid!", cub3d));
	if (valid_characters(cub3d->map) == 1)
		return (error_msg("Character invalid!", cub3d));
	if (valid_edge(cub3d->map) == 1)
		return (error_msg("he bord of the map must be 1!", cub3d));
	return (0);
}
