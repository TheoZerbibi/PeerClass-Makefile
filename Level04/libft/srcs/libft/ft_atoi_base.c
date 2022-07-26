/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:38:20 by thzeribi          #+#    #+#             */
/*   Updated: 2022/07/23 19:38:57 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	ft_in_base(char c, char *base)
{
	int i;

	i = -1;
	while (base[++i])
		if (c == base[i])
			return (i);
	return (-1);
}

static int
	ft_baselen(char *base)
{
	int size;

	size = -1;
	while (base[++size])
		if (base[size] == '+' || base[size] == '-' || base[size] == ' '
			|| ft_in_base(base[size], base + size + 1) >= 0
			|| (base[size] >= 9 && base[size] <= 13))
			return (0);
	return (size);
}

int
	ft_atoi_base(char *str, char *base)
{
	int i;
	int n;
	int negative;
	int size;

	if ((size = ft_baselen(base)) < 2)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	negative = 0;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			negative = 1 - negative;
	n = 0;
	while ((i = ft_in_base(*str, base)) >= 0)
	{
		n = n * size + i;
		str++;
	}
	if (negative)
		n *= -1;
	return (n);
}