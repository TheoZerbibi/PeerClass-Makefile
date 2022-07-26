/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeribi <tzeribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:48:03 by thzeribi          #+#    #+#             */
/*   Updated: 2021/10/29 15:12:17 by tzeribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	size;
	char	*res;

	i = 0;
	if (s1 == NULL)
		return (0);
	if (set == NULL)
		return ((char *)s1);
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	size = ft_strlen(&s1[i]);
	if (size != 0)
	{
		while (s1[i + size - 1] && ft_strchr(set, s1[i + size - 1]) != NULL)
			size--;
	}
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (0);
	ft_strlcpy(res, &s1[i], size + 1);
	res[size] = '\0';
	return (res);
}
