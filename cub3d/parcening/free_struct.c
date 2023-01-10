/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:09:47 by coder             #+#    #+#             */
/*   Updated: 2023/01/10 13:05:20 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_images(t_cub3d *cub)
{
	mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.no.img);
	mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.so.img);
	mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.we.img);
	mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.ea.img);
}

void	free_mlx_all(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
		free(cub->textures[i++]);
	mlx_destroy_image(cub->s_mlx.mlx, cub->img.img);
	mlx_destroy_window(cub->s_mlx.mlx, cub->s_mlx.win);
	ft_free_ptr(&cub->s_mlx.mlx);
}

void	free_struct(t_cub3d *cub)
{
	if (cub->path_texture != NULL)
		ft_free_triple(cub->path_texture);
	if (cub->colors_cf != NULL)
		ft_free_triple(cub->colors_cf);
	if (cub->map != NULL)
		ft_free_split(cub->map);
	if (cub->map_content != NULL)
		ft_free_split(cub->map_content);
}

/* Free the allocated memory of the map and close the window */
int	close_win(t_cub3d *cub)
{
	free_struct(cub);
	free_mlx_all(cub);
	exit(0);
}
