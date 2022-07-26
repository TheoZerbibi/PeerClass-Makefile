/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_ext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:51:35 by thzeribi          #+#    #+#             */
/*   Updated: 2021/04/26 14:08:19 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_file_ext(const char *filename)
{
	const char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename)
		return (NULL);
	return (dot + 1);
}
