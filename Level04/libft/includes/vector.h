/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:33:25 by thzeribi          #+#    #+#             */
/*   Updated: 2021/06/17 17:04:14 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "libft.h"
# include <stddef.h>
# include "string.h"

typedef struct s_vector
{
	void	*bytes;
	size_t	len;
	size_t	available;
	size_t	size;
	size_t	elem_size;
	size_t	elem_nbr;
}			t_vector;

t_vector		*new_vector(size_t count, size_t size);
t_vector		*vector_resize(t_vector *vector, size_t new_size);
t_vector		*vector_append(t_vector *vector, void *add, size_t count);
void			free_vector(t_vector *vector);
void			vector_iter(t_vector *vector, void (*func)());
void			vector_clear(t_vector *vector, void (*func)());
void			*vector_end(t_vector *vector);
void			*vector_at(t_vector *vector, size_t index);

#endif
