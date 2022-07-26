/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 00:59:11 by thzeribi          #+#    #+#             */
/*   Updated: 2019/11/07 09:41:37 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;
	unsigned char	*src2;
	size_t			index;

	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	index = 0;
	if (dst2 > src2)
	{
		index = len;
		while (index > 0)
		{
			dst2[index - 1] = src2[index - 1];
			index--;
		}
	}
	else if (dst2 < src2)
		ft_memcpy(dst2, src2, len);
	return (dst2);
}
