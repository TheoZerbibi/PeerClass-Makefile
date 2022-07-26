/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeribi <tzeribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 02:03:32 by thzeribi          #+#    #+#             */
/*   Updated: 2021/10/29 15:11:30 by tzeribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*res;
	size_t	sign;
	size_t	i;

	i = 0;
	sign = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		sign = 1;
	res = malloc(sizeof(char) * (ft_nbrlen(n) + 1));
	if (!res)
		return (NULL);
	while (n != 0)
	{
		if (sign)
			res[i++] = (-1 * (n % 10)) + 48;
		else
			res[i++] = (n % 10) + 48;
		n /= 10;
	}
	if (sign)
		res[i++] = '-';
	res[i] = '\0';
	return (ft_strrev(res));
}
