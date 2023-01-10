/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:58:03 by mal-hadr          #+#    #+#             */
/*   Updated: 2023/01/10 12:58:06 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	using_gnl(char **content_map, int fd)
{
	int	i;

	i = 0;
	while (get_next_line(fd, &content_map[i++]))
		;
	content_map[i] = NULL;
}

//Use GNL to store all content of the map into a char **
char	**get_map(char *map_path)
{
	char	**map_content;
	char	c;
	int		fd;
	int		rslt;
	int		num_line;

	num_line = 1;
	fd = open(map_path, O_RDONLY);
	rslt = read(fd, &c, 1);
	if (rslt == 0)
		return (NULL);
	while (rslt > 0)
	{
		if (c == '\n' || c == (char)EOF)
			num_line++;
		rslt = read(fd, &c, 1);
	}
	close(fd);
	fd = open(map_path, O_RDONLY);
	map_content = malloc((num_line + 1) * sizeof(char *));
	using_gnl(map_content, fd);
	close(fd);
	return (map_content);
}

// it will count the line of the map except the empty line
int	count_num_line(char **map_content)
{
	int		i;
	int		count_line;
	char	**line;

	if (!map_content)
		return (0);
	i = 0;
	count_line = 0;
	while (map_content[i])
	{
		line = ft_split(map_content[i], ' ');
		if (*line != NULL)
			count_line++;
		ft_free_split(line);
		i++;
	}
	return (count_line);
}

//remove all empty line of the content map
char	**remove_empty_line(char **map_content)
{
	int		i;
	int		j;
	char	**n_map;
	char	**line;

	if (!map_content)
		return (NULL);
	i = 0;
	j = 0;
	n_map = ft_calloc(count_num_line(map_content) + 1, sizeof(char *));
	while (map_content[i])
	{
		line = ft_split(map_content[i], ' ');
		if (*line != NULL)
			n_map[j++] = ft_strdup(map_content[i]);
		ft_free_split(line);
		i++;
	}
	ft_free_split(map_content);
	map_content = NULL;
	return (n_map);
}

// Store and return only the blueprint of the map.
char	**store_map_blueprint(char **content_map)
{
	char	**map;
	int		i;
	int		j;

	if (!content_map)
		return (NULL);
	map = ft_calloc(ft_strlen_split(content_map) - 5, sizeof(char *));
	i = 6;
	j = 0;
	while (content_map[i])
		map[j++] = ft_strdup(content_map[i++]);
	return (map);
}
