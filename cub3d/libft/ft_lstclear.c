/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:55:30 by mal-hadr          #+#    #+#             */
/*   Updated: 2021/10/20 13:55:36 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;

	elem = 0;
	if (!lst)
		return ;
	while (*lst)
	{
		elem = *lst;
		*lst = (*lst)->next;
		del((elem)->content);
		free(elem);
	}
}
