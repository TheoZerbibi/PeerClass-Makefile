/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:05:52 by thzeribi          #+#    #+#             */
/*   Updated: 2021/06/23 07:58:07 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

t_gc_list
	**get_gc_list(void)
{
	static t_gc_list	*gc_list = NULL;

	return (&gc_list);
}
