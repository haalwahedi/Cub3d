/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:21:43 by mal-hadr          #+#    #+#             */
/*   Updated: 2021/10/20 13:24:26 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long n)
{
	int	size;

	size = 1;
	while (n > 9)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static long	multiplier(int size)
{
	long	mul;

	mul = 1;
	while (size > 1)
	{
		mul = mul * 10;
		size--;
	}
	return (mul);
}

static int	check_negative(long *n, char **str, int *i)
{
	int		negative;
	int		size;

	negative = 0;
	if (*n < 0)
	{
		*n = *n * -1;
		*i = *i + 1;
		negative = 1;
	}
	size = get_size(*n);
	if (negative)
		size++;
	*str = (char *)malloc(sizeof(char) * (size + 1));
	if (!*str)
		return (0);
	if (negative)
	{
		*str[0] = '-';
		return (size - 1);
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	mult;
	long	c;
	int		size;
	int		i;

	size = 1;
	i = 0;
	c = (long)n;
	size = check_negative(&c, &str, &i);
	if (!str)
		return (0);
	while (size > 0)
	{
		mult = multiplier(size);
		str[i] = c / mult + '0';
		c = c - (mult * (str[i] - '0'));
		size--;
		i++;
	}
	str[i] = '\0';
	return (str);
}
