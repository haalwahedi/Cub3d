/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:25:47 by mal-hadr          #+#    #+#             */
/*   Updated: 2023/01/10 12:25:53 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* Prints a error message  */
int	error_msg(char	*msg, t_cub3d *cub3d)
{
	if (cub3d != NULL)
		free_struct(cub3d);
	printf("\e[31m\e[1mError: %s \e[0m \n", msg);
	exit (EXIT_FAILURE);
}
