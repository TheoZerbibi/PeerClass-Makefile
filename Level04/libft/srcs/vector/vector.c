/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeribi <tzeribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:47:26 by thzeribi          #+#    #+#             */
/*   Updated: 2021/10/29 15:12:17 by tzeribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector
	*new_vector(size_t count, size_t size)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->bytes = ft_calloc(count, size + 1);
	if (!vector->bytes)
	{
		gc_free(vector->bytes);
		return (NULL);
	}
	vector->len = 0;
	vector->size = count;
	vector->available = count;
	vector->elem_size = size;
	vector->elem_nbr = 0;
	return (vector);
}

t_vector
	*vector_resize(t_vector *vector, size_t new_size)
{
	char	*new;
	size_t	cpy;

	new = ft_calloc(new_size, vector->elem_size);
	if (!new)
		return (NULL);
	if (vector->len > new_size)
	{
		cpy = new_size;
		vector->available = 0;
		vector->len = cpy;
		vector->size = new_size;
	}
	else
	{
		cpy = vector->len;
		vector->available += new_size - vector->size;
		vector->size = new_size;
	}
	ft_memcpy(new, vector->bytes, cpy * vector->elem_size);
	gc_free(vector->bytes);
	vector->bytes = new;
	return (vector);
}

t_vector
	*vector_append(t_vector *vector, void *add, size_t count)
{
	void	*dst;

	if (count > vector->available)
	{
		if (!vector_resize(vector, (vector->size + count) * 2))
			return (NULL);
	}
	dst = (vector->bytes + vector->len * vector->elem_size);
	ft_memcpy(dst, add, count * vector->elem_size);
	vector->len += count;
	vector->available -= count;
	vector->elem_nbr++;
	return (vector);
}

void
	vector_iter(t_vector *vector, void (*func)())
{
	size_t	index;

	index = 0;
	while (index < vector->len)
	{
		func(vector_at(vector, index));
		index++;
	}
}

void
	vector_clear(t_vector *vector, void (*func)())
{
	if (!vector)
		return ;
	if (func)
		vector_iter(vector, (void *)func);
	free_vector(vector);
}
