/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:51:05 by mal-hadr          #+#    #+#             */
/*   Updated: 2023/01/10 12:52:58 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_line(char *s, size_t len)
{
	char			*line;
	size_t			i;

	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static int	add_line(char **str, char **line)
{
	int		size;
	char	*tmp;

	size = 0;
	while ((*str)[size] != '\n' && (*str)[size])
		size++;
	if ((*str)[size] == '\0')
	{
		*line = ft_strdup(*str);
		if (*str != NULL)
		{
			free(*str);
			*str = NULL;
		}
		return (0);
	}
	*line = ft_line(*str, size);
	tmp = ft_strdup((*str) + size + 1);
	free(*str);
	*str = tmp;
	return (1);
}

static int	output(char **str, char **line, ssize_t size)
{
	if (size < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	else if (size == 0 && *str == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (add_line(str, line));
}

int	get_next_line(int fd, char **line)
{
	static char	*str[10240];
	t_var		var;

	var.buffer = malloc(BUFFER_SIZE + 1);
	if (!var.buffer)
		return (-1);
	var.size = read(fd, var.buffer, BUFFER_SIZE);
	while (var.size > 0)
	{
		var.buffer[var.size] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(var.buffer);
		else
		{
			var.tmp = ft_strjoin(str[fd], var.buffer);
			free(str[fd]);
			str[fd] = var.tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
		var.size = read(fd, var.buffer, BUFFER_SIZE);
	}
	free(var.buffer);
	return (output(&str[fd], line, var.size));
}
