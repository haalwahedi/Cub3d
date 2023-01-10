/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:35:18 by mal-hadr          #+#    #+#             */
/*   Updated: 2023/01/10 12:35:50 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//Check if all texture file exist.
int	texture_file_exist(char ***texture)
{
	int	i;

	i = -1;
	while (texture[++i])
		if (file_exist(texture[i][1]) == 1 ||
			check_extenstion(texture[i][1], ".xpm") == 1)
			return (1);
	return (0);
}

static char	***create_sides_of_map(void)
{
	char	***sides;

	sides = ft_calloc(5, sizeof(char *));
	sides[0] = ft_split("NO FILE", ' ');
	sides[1] = ft_split("SO FILE", ' ');
	sides[2] = ft_split("WE FILE", ' ');
	sides[3] = ft_split("EA FILE", ' ');
	return (sides);
}

static void	compare_textures(char ***textures, char ***sides, int *j)
{
	int	i;

	i = -1;
	while ((++i < 6 && textures[i][0]) && *j != 4)
	{
		if (ft_strcmp(textures[i][0], sides[*j][0]) == 0)
		{
			free(sides[*j][1]);
			if (textures[i][1])
			{
				sides[*j][1] = ft_strdup(textures[i][1]);
				*j += 1;
			}
			i = -1;
		}
	}
}

//Check if map has all necessary texture, 
//Store the line of each texture inside a triple pointer.
//On Sucess a triple pointer with the name and file of texture.
char	***valid_texture(char **map_content)
{
	int		i;
	int		j;
	char	***textures;
	char	***sides;

	i = -1;
	sides = create_sides_of_map();
	textures = ft_calloc(7, sizeof(char *));
	while (++i < 6 && i < ft_strlen_split(map_content))
		textures[i] = ft_split(map_content[i], ' ');
	i = -1;
	j = 0;
	compare_textures(textures, sides, &j);
	ft_free_triple(textures);
	if (j != 4)
	{
		ft_free_triple(sides);
		return (NULL);
	}
	return (sides);
}
