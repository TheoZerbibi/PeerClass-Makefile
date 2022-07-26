/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeribi <tzeribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:10:57 by thzeribi          #+#    #+#             */
/*   Updated: 2021/10/30 07:29:54 by tzeribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

void
	gc_free(void *gc)
{
	t_gc_list	**gc_list;
	t_gc_list	*current;
	t_gc_list	*previous;

	if (gc != NULL)
	{
		gc_list = get_gc_list();
		current = *gc_list;
		previous = NULL;
		while (current->ptr != gc)
		{
			previous = current;
			current = current->next;
		}
		if (previous == NULL)
			*gc_list = current->next;
		else
			previous->next = current->next;
		ft_memdel((void **)&current->ptr);
		ft_memdel((void **)&current);
		gc = NULL;
	}
}

void
	gc_clear_all(void)
{
	t_gc_list	**gc_list;
	t_gc_list	*copy_list;
	t_gc_list	*next_list;

	gc_list = get_gc_list();
	copy_list = *gc_list;
	while (copy_list)
	{
		next_list = copy_list->next;
		ft_memdel((void **)&copy_list->ptr);
		ft_memdel((void **)copy_list);
		copy_list = next_list;
	}
}
