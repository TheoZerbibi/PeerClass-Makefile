/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_trace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:29:09 by thzeribi          #+#    #+#             */
/*   Updated: 2021/07/29 16:30:22 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_stack_trace(char *caller)
{
	void	*array[10];
	size_t	size;

	printf("Stack Trace Start for %s\n", caller);
	size = backtrace(array, 10);
	backtrace_symbols_fd(array, size, 2);
	printf("Stack Trace End\n");
}
