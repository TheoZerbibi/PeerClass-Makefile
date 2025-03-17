/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:35:02 by thzeribi          #+#    #+#             */
/*   Updated: 2021/01/01 13:13:07 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (!src)
		return (0);
	i = ft_strlen((char *)src);
	if (!dst)
		return (i);
	j = 0;
	while (src[j] != '\0' && j < dstsize)
	{
		dst[j] = src[j];
		j++;
	}
	if (dstsize > 0)
	{
		if (i == 0 || i < dstsize)
			dst[j] = '\0';
		else
			dst[j - 1] = '\0';
	}
	return (i);
}
