/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeribi <tzeribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:53:06 by thzeribi          #+#    #+#             */
/*   Updated: 2021/10/29 15:11:05 by tzeribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*memzone;

	memzone = malloc(count * size);
	if (!memzone)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		memzone[i] = 0;
		i++;
	}
	return ((void *)memzone);
}
