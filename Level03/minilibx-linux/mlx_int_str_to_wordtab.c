/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_str_to_wordtab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlie Root <ol@epitech.net>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/08/13 11:36:09 by Charlie Root      #+#    #+#             */
/*   Updated: 2021/11/01 17:46:07 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int	mlx_int_str_str(char *str, char *find, int len)
{
	int		len_f;
	int		pos;
	char	*s;
	char	*f;

	len_f = strlen(find);
	if (len_f > len)
		return (-1);
	pos = 0;
	while (*(str + len_f - 1))
	{
		s = str;
		f = find;
		while (*(f++) == *(s++))
			if (!*f)
				return (pos);
		str++;
		pos++;
	}
	return (-1);
}

int	mlx_int_str_str_cote(char *str, char *find, int len)
{
	int		len_f;
	int		pos;
	char	*s;
	char	*f;
	int		cote;

	len_f = strlen(find);
	if (len_f > len)
		return (-1);
	cote = 0;
	pos = 0;
	while (*(str + len_f - 1))
	{
		if (*str == '"')
			cote = 1 - cote;
		if (!cote)
		{
			s = str;
			f = find;
			while (*(f++) == *(s++))
				if (!*f)
					return (pos);
		}
		str++;
		pos++;
	}
	return (-1);
}

static int	mlx_int_str_count_word(char *str, int len)
{
	int		pos;
	int		nb_word;

	nb_word = 0;
	pos = 0;
	while (pos < len)
	{
		while (str[pos] == ' ' || str[pos] == '\t')
			pos++;
		if (str[pos])
			nb_word++;
		while (str[pos] && str[pos] != ' ' && str[pos] != '\t')
			pos++;
	}
	return (nb_word);
}

static void	mlx_int_str_init_wordtab(char *str, char **tab, int len)
{
	int		pos;
	int		nb_word;

	nb_word = 0;
	pos = 0;
	while (pos < len)
	{
		while (str[pos] == ' ' || str[pos] == '\t')
			str[pos++] = 0;
		if (str[pos])
			tab[nb_word++] = str + pos;
		while (str[pos] && str[pos] != ' ' && str[pos] != '\t')
			pos++;
	}
	tab[nb_word] = 0;
}

char	**mlx_int_str_to_wordtab(char *str)
{
	char	**tab;
	int		len;
	int		nb_word;

	len = strlen(str);
	nb_word = mlx_int_str_count_word(str, len);
	tab = (char **)malloc((1 + nb_word) * sizeof(*tab));
	if (!tab)
		return ((char **)0);
	mlx_int_str_init_wordtab(str, tab, len);
	return (tab);
}
