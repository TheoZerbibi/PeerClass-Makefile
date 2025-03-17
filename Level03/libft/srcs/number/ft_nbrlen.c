/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:10:40 by thzeribi          #+#    #+#             */
/*   Updated: 2021/01/01 13:10:02 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(long int nbr)
{
	size_t	size;

	size = 0;
	if (nbr <= 0)
		size = 1;
	while (nbr != 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}
