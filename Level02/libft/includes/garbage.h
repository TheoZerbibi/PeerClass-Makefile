/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:05:56 by thzeribi          #+#    #+#             */
/*   Updated: 2021/06/15 17:34:56 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include "libft.h"

typedef struct s_gc_list
{
	void				*ptr;
	struct s_gc_list	*next;
}			t_gc_list;

t_gc_list	**get_gc_list(void);
void		gc_clear_all(void);
void		gc_free(void *gc);
void		*gc_malloc(size_t size);

#endif
