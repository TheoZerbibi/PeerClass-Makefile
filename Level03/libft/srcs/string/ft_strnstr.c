/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:37:29 by thzeribi          #+#    #+#             */
/*   Updated: 2021/04/01 17:41:20 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	size;

	size = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[size] != '\0' && size < len)
	{
		if (!haystack[size])
			return (NULL);
		i = 0;
		while (needle[i] == haystack[i + size] && i + size < len)
		{
			if (needle[i + 1] == '\0')
				return ((char *)haystack + size);
			i++;
		}
		size++;
	}
	return (0);
}
