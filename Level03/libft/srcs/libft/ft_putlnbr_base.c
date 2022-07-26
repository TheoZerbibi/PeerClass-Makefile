/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:49:04 by thzeribi          #+#    #+#             */
/*   Updated: 2021/04/26 14:41:11 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Print is a Boolean
** print = 1 (True), function return size + write
** print = 0 (False), function only return size
*/

int	ft_putlnbr_base(unsigned long int nb, char *b, int up, int p)
{
	int				i;
	unsigned int	base_len;

	base_len = ft_strlen(b);
	i = 0;
	if (nb < base_len)
	{
		if (p == 1)
		{
			if (up == 1)
				ft_putchar(ft_toupper(b[nb]));
			else
				ft_putchar(b[nb]);
		}
		return (1);
	}
	else
	{
		i += ft_putlnbr_base(nb / base_len, b, up, p);
		i += ft_putlnbr_base(nb % base_len, b, up, p);
	}
	return (i);
}
