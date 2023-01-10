/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:27:57 by mal-hadr          #+#    #+#             */
/*   Updated: 2023/01/10 12:28:22 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_rgb	check_rgb_color(char **str)
{
	char	*color;
	char	**color_split;
	t_rgb	rgb;

	rgb.status = 0;
	color = ft_split_rev(str);
	color_split = ft_split(color + 1, ',');
	free(color);
	if (ft_strlen_split(color_split) != 3)
	{
		ft_free_split(color_split);
		rgb.status = 1;
		return (rgb);
	}
	if (verify_collor(&rgb, color_split) == 1)
		return (rgb);
	rgb.red = ft_atoi(color_split[0]);
	rgb.green = ft_atoi(color_split[1]);
	rgb.blue = ft_atoi(color_split[2]);
	ft_free_split(color_split);
	if (rgb.blue < 0 || rgb.green < 0 || rgb.red < 0
		|| rgb.blue > 255 || rgb.green > 255 || rgb.red > 255)
		rgb.status = 1;
	return (rgb);
}

t_collor	check_color(char ***colors)
{
	t_collor	collor;

	collor.status = 0;
	if (ft_strcmp(colors[0][0], "F") == 0)
	{
		collor.cell_rgb = check_rgb_color(colors[1]);
		collor.floor_rgb = check_rgb_color(colors[0]);
	}
	else
	{
		collor.cell_rgb = check_rgb_color(colors[0]);
		collor.floor_rgb = check_rgb_color(colors[1]);
	}
	if (collor.cell_rgb.status == 1 || collor.floor_rgb.status == 1)
		collor.status = 1;
	return (collor);
}

// Check if the colors of ceilling and floor its on right format.
char	***valid_ceilling_and_floor_color(char **map_content)
{
	char	***collors;
	char	**key_val;
	int		i;
	int		index;

	i = -1;
	index = 0;
	collors = ft_calloc(3, sizeof(char *));
	while (++i < 6)
	{
		key_val = ft_split(map_content[i], ' ');
		if (ft_strcmp(key_val[0], "F") == 0 || ft_strcmp(key_val[0], "C") == 0)
			collors[index++] = ft_split(map_content[i], ' ');
		ft_free_split(key_val);
	}
	if (collors[0] == NULL || collors[1] == NULL
		|| ft_strlen_split(collors[0]) < 2 || ft_strlen_split(collors[0]) < 2
		|| ft_strcmp(collors[0][0], collors[1][0]) == 0)
	{
		ft_free_triple(collors);
		return (NULL);
	}
	return (collors);
}

static int	check_player(char pos)
{
	if (pos == 'N' || pos == 'W' || pos == 'S' || pos == 'E')
		return (1);
	return (0);
}

//Check if have only the allowed characters on the map.
int	valid_characters(char **map)
{
	int		i;
	int		j;
	int		side;

	j = -1;
	i = -1;
	side = 0;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == ' ')
				continue ;
			else if (check_player(map[i][j]))
				side++;
			else
				return (error_msg("Character invalid!", NULL));
		}
		j = -1;
	}
	if (side == 0)
		return (1);
	else if (side > 1)
		return (error_msg("Only one side of position is allowed!", NULL));
	return (0);
}
