/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:12:48 by thzeribi          #+#    #+#             */
/*   Updated: 2022/09/22 16:42:54 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countstr(char const *s1, char const c)
{
	int	nb;
	int	cursor;
	int	len;

	nb = 0;
	cursor = 0;
	len = 0;
	while (s1[cursor])
	{
		if (s1[cursor] == c && len != 0)
		{
			len = 0;
			nb++;
		}
		else if (s1[cursor] != c)
			len++;
		cursor++;
	}
	if (len != 0)
		nb++;
	return (nb);
}

static int	freeall(char **strs, int len)
{
	int	count;

	count = 0;
	while (count <= len)
	{
		free(strs[count]);
		count++;
	}
	free(strs);
	return (0);
}

static int	allocstrs(char const *s1, char const c, int nb, char **strs)
{
	int	count;
	int	cursor;
	int	len;

	cursor = 0;
	count = 0;
	while (count < nb)
	{
		len = 0;
		while (s1[cursor] == c)
			cursor++;
		while (s1[len + cursor] && s1[len + cursor] != c)
			len++;
		strs[count] = (char *)malloc(sizeof(char) * (len + 1));
		if (!strs[count])
			return (freeall(strs, count));
		count++;
		cursor = cursor + len;
	}
	strs[count] = (char *)malloc(sizeof(char));
	return (1);
}

static char	**fillstrs(char const *s1, char const c, char **strs, int nb)
{
	int		count;
	int		cursor;
	int		count2;

	cursor = 0;
	count = 0;
	while (count < nb)
	{
		count2 = 0;
		while (s1[cursor] == c && s1[cursor])
			cursor++;
		while (s1[cursor] != c && s1[cursor])
		{
			strs[count][count2] = s1[cursor];
			cursor++;
			count2++;
		}
		strs[count][count2] = '\0';
		count++;
	}
	strs[count] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	int		nb;
	char	**strs;

	if (s == 0)
		return (0);
	nb = countstr(s, c);
	strs = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!strs)
		return (0);
	if (!(allocstrs(s, c, nb, strs)))
		return (0);
	strs = fillstrs(s, c, strs, nb);
	return (strs);
}
