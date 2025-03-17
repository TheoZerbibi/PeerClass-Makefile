/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:33:29 by thzeribi          #+#    #+#             */
/*   Updated: 2021/10/31 10:43:57 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_add_char(char c)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * 2);
	if (!new)
		return (NULL);
	new[0] = c;
	new[1] = '\0';
	return (new);
}

char	*ft_charcat(char *s1, const char s2)
{
	char	*final;
	int		i;

	if (!s2)
		return (NULL);
	if (!s1)
		return (str_add_char(s2));
	final = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!final)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		final[i] = s1[i];
	free(s1);
	final[i++] = s2;
	final[i] = '\0';
	return (final);
}
