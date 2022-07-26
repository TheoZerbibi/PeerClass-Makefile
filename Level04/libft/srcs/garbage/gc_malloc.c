/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:41:37 by thzeribi          #+#    #+#             */
/*   Updated: 2021/07/29 16:52:37 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

void
	*gc_malloc(size_t size)
{
	t_gc_list	**gc_list;
	t_gc_list	*new_list;
	t_gc_list	*copy_list;

	new_list = NULL;
	gc_list = get_gc_list();
	copy_list = *gc_list;
	new_list = malloc(sizeof(t_gc_list));
	if (new_list == NULL)
		exit(0);
	ft_bzero(new_list, sizeof(t_gc_list));
	new_list->ptr = malloc(size);
	if (new_list->ptr == NULL)
	{
		ft_memdel((void **)&new_list);
		exit(0);
	}
	ft_bzero(new_list->ptr, sizeof(size));
	new_list->next = copy_list;
	*gc_list = new_list;
	return (new_list->ptr);
}
