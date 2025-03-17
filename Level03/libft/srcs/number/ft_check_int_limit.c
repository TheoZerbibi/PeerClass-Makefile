/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_int_limit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 02:51:22 by thzeribi          #+#    #+#             */
/*   Updated: 2021/10/27 23:14:29 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_check_int_limit(const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	if (!(*str))
		return (FALSE);
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str < ':' && *str > '/'))
	{
		res = res * 10 + (*str - 48);
		str++;
		if ((res * sign) < INT_MIN || (res * sign) > INT_MAX)
			return (FALSE);
	}
	if (*str && (*str >= ':' || *str <= '/'))
		return (FALSE);
	return (TRUE);
}
