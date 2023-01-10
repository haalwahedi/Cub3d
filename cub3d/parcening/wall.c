/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:36:21 by mal-hadr          #+#    #+#             */
/*   Updated: 2023/01/10 12:36:48 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//Check if the current position of the map is space. 
//Looking up, down, left, right.
static int	check_around(char **map, int line, int col)
{
	int	len_up;
	int	len_down;

	len_up = ft_strlen(map[line - 1]);
	len_down = ft_strlen(map[line + 1]);
	if (map[line][col - 1])
		if (col < len_up && map[line - 1][col] == ' ')
			return (0);
	if (map[line][col + 1])
		if (map[line][col + 1] == ' ')
			return (0);
	if (col < len_up)
		if (map[line - 1][col] == ' ')
			return (0);
	if (col < len_down)
		if (map[line + 1][col] == ' ')
			return (0);
	if (col > len_up - 1 || col > len_down - 1)
		return (0);
	return (1);
}

//Check if the wall inside the map is valid.
int	valid_wall_inside_map(char **map)
{
	int		line;
	size_t	col;

	line = 0;
	col = 0;
	while (++line < ft_strlen_split(map) - 1)
	{
		while (++col < ft_strlen(map[line]) - 1)
		{
			if (check_around(map, line, col) == 0)
			{
				if (map[line][col] != '1' && map[line][col] != ' ')
					return (error_msg("The wall inside the map must be 1!",
							NULL));
			}
		}
		col = 0;
	}
	return (0);
}

//Check if the top and the bottom is fulled of number 1.
int	valid_top_bottom(char **map)
{
	int		i;
	int		len;

	len = ft_strlen_split(map) - 1;
	i = -1;
	while (map[0][++i])
	{
		if (map[0][i] == '1' || map[0][i] == ' ' || map[0][i] == '\t')
			continue ;
		else
			return (error_msg("the bord of the map must be 1!", NULL));
	}
	i = -1;
	while (map[len][++i])
	{
		if (map[len][i] == '1' || map[len][i] == ' ' || map[len][i] == '\t')
			continue ;
		else
			return (error_msg("the bord of the map must be 1!", NULL));
	}
	return (0);
}

//Check if the wall map of left and right is fulled of number 1.
int	valid_left_right(char **map)
{
	int		i;
	int		len;

	len = ft_strlen(map[0]) - 1;
	i = -1;
	while (map[++i] && map[i][0])
	{
		if (map[i][0] == '1' || map[i][0] == ' ')
			continue ;
		else
			return (error_msg("the bord of the map must be 1!", NULL));
	}
	i = -1;
	while (map[++i] && map[i][len])
	{
		if (!(map[i][len] == '1' || map[i][len] == ' '))
			return (error_msg("the bord of the map must be 1!", NULL));
		if (map[i + 1])
			len = ft_strlen(map[i + 1]) - 1;
	}
	return (0);
}

//Check if the edge of the map is valid.
int	valid_edge(char **map)
{
	if (valid_top_bottom(map) == 1)
		return (1);
	if (valid_left_right(map) == 1)
		return (1);
	if (valid_wall_inside_map(map) == 1)
		return (1);
	return (0);
}
