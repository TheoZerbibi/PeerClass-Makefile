/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:19:42 by thzeribi          #+#    #+#             */
/*   Updated: 2021/10/19 18:21:53 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_contain(char *src, char c)
{
	int	i;

	i = -1;
	while (src)
	{
		if (src[++i] == c)
			return (TRUE);
	}
	return (FALSE);
}
