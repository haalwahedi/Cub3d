/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:46:10 by mal-hadr          #+#    #+#             */
/*   Updated: 2023/01/10 12:55:56 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_release(int key, t_cub3d *cub)
{
	if (key == RIGHT)
		cub->player.side_direction = 0;
	if (key == ARROW_RIGHT)
		cub->player.turn_direction = 0;
	if (key == LEFT)
		cub->player.side_direction = 0;
	if (key == ARROW_LEFT)
		cub->player.turn_direction = 0;
	if (key == TOP)
		cub->player.walk_direction = 0;
	if (key == DOWN)
		cub->player.walk_direction = 0;
	return (0);
}

void	start_game(t_cub3d *cub)
{
	t_data	img_p;

	ft_bzero(&img_p, sizeof(t_data));
	cub->s_mlx.mlx = mlx_init();
	cub->s_mlx.win = mlx_new_window(cub->s_mlx.mlx, WIDTH, HEIGHT, "cub3D");
	build_main_img(cub);
	setup(cub);
	mlx_hook(cub->s_mlx.win, 17, 0, close_win, (void *)cub);
	mlx_hook(cub->s_mlx.win, 2, 1L << 0, action, (void *)cub);
	mlx_hook(cub->s_mlx.win, 3, 1L << 1, key_release, (void *)cub);
	mlx_loop_hook(cub->s_mlx.mlx, action_loop, (void *)cub);
	mlx_loop(cub->s_mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_cub3d	cubed;

	if (invalid_arg(argc, argv) == 1)
		return (3);
	ft_bzero(&cubed, sizeof(t_cub3d));
	if (check_map(argv[1], &cubed) == 1)
		return (4);
	start_game(&cubed);
	free_struct(&cubed);
}
