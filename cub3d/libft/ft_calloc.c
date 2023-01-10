/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:21:36 by mal-hadr          #+#    #+#             */
/*   Updated: 2023/01/03 17:08:14 by mnyalhdrmy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(count * size);
	if (!str)
		return (NULL);
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	size_t	*ptr;
// 	size_t	total;

// 	total = nmemb * size;
// 	if (total > INT_MAX)
// 		return (NULL);
// 	ptr = malloc(total);
// 	if (ptr == NULL)
// 		return (NULL);
// 	ft_memset(ptr, 0, total);
// 	return ((void *)ptr);
// }
