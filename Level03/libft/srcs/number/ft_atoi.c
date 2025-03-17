/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:03:03 by thzeribi          #+#    #+#             */
/*   Updated: 2023/02/28 20:36:54 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	result;

	i = 0;
	result = 0;
	while (ft_isspace(str[i]) == 1 && str[i] == '0')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (INT_MIN);
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		result = result * 10 + str[i] - '0';
		if (result > INT_MAX)
			return (INT_MIN);
		i++;
	}
	return ((int)result);
}
