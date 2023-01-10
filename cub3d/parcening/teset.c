/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:33:12 by mal-hadr          #+#    #+#             */
/*   Updated: 2023/01/10 12:35:12 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_free_split(char **str)
{
	int	count;

	count = 0;
	if (!str)
		return (NULL);
	while (str[count])
		free(str[count++]);
	free(str);
	return (NULL);
}

// it will count the line of the map except the empty line
int	count_num_line(char **map_content)
{
	int		i;
	int		num_line;
	char	**line;

	if (!map_content)
		return (0);
	i = 0;
	num_line = 0;
	while (map_content[i])
	{
		line = ft_split(map_content[i], ' ');
		if (*line != NULL)
			num_line++;
		ft_free_split(line);
		i++;
	}
	return (num_line);
}

//remove all empty line of the content map
char	**remove_empty_line(char **map_content)
{
	int		i;
	int		j;
	char	**line;
	char	**num_map;

	if (!map_content)
		return (NULL);
	i = 0;
	j = 0;
	num_map = ft_calloc(count_num_line(map_content) + 1, sizeof(char *));
	while (map_content[i])
	{
		line = ft_split(map_content[i], ' ');
		if (*line != NULL)
			num_map[j++] = ft_strdup(map_content[i]);
		ft_free_split(map_content);
		i++;
	}
	ft_free_split(map_content);
	map_content = NULL;
	return (num_map);
}

static void	ft_gnl(char **content_map, int fd)
{
	int	i;

	i = 0;
	while (get_next_line(fd, &content_map[i]))
	{
		i++;
	}
	content_map[i] = NULL;
}

//using GNL to store all content of the map int to char **.
char	**get_map(char *map_path)
{
	char	**map_content;
	char	c;
	int		fd;
	int		rsult;
	int		num_line;

	num_line = 1;
	map_content = NULL;
	fd = open(map_path, O_RDONLY);
	rsult = read (fd, &c, 1);
	if (rsult == 0)
		return (NULL);
	while (rsult > 0)
	{
		if (c == '\n' || c == EOF)
			num_line++;
		rsult = read(fd, &c, 1);
	}
	close(fd);
	fd = open(map_path, O_RDONLY);
	map_path = malloc((num_line + 1) * sizeof(char *));
	ft_gnl(map_content, fd);
	printf("test\n");
	close(fd);
	return (map_content);
}
