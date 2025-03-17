/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeribi <tzeribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 02:26:47 by thzeribi          #+#    #+#             */
/*   Updated: 2021/10/29 15:11:25 by tzeribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizemalloc(long long unsigned int i)
{
	long unsigned int	j;
	int					size;

	j = i;
	size = 0;
	while (j > 0)
	{
		size++;
		j = j / 16;
	}
	return (size);
}

char	*ft_itohexa(long long unsigned int i, char *base)
{
	char	*str;
	int		size;

	if (i == 0)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (NULL);
		str[0] = base[0];
		str[1] = '\0';
		return (str);
	}
	size = ft_sizemalloc(i);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	size--;
	while (i > 0)
	{
		str[size] = base[i % 16];
		i = i / 16;
		size--;
	}
	return (str);
}

char	*ft_itoa_base(long int num, char *base)
{
	return (ft_itohexa(num, base));
}
