/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:26:11 by mal-hadr          #+#    #+#             */
/*   Updated: 2023/01/10 12:27:29 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// this function check the extention should be .cub
int	check_extenstion(char *map_name, char *extention)
{
	int	len_map_name;
	int	len_extantion;
	int	i;

	len_map_name = ft_strlen(map_name);
	len_extantion = ft_strlen(extention);
	i = 0;
	while (len_extantion > 0)
	{
		if (extention[--len_extantion] == map_name[--len_map_name])
			i++;
		else
			return (1);
	}
	return (0);
}

// check the file if its there or no
int	file_exist(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

// check the validation of the map
int	invalid_arg(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		return (error_msg("INVALED ARGUMENT!", NULL));
	else if (check_extenstion(argv[1], ".cub") == 1)
		return (error_msg("WRONG EXTENSTION!", NULL));
	else if (file_exist(argv[1]))
		return (error_msg("FILE NIT EXIST!", NULL));
	return (0);
}
