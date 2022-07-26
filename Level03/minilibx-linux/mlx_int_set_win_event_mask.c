/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_set_win_event_mask.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlie Root <ol@epitech.net>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/08/03 11:49:06 by Charlie Root      #+#    #+#             */
/*   Updated: 2021/10/21 17:03:57 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mlx_int.h"

void	mlx_int_set_win_event_mask(t_xvar *xvar)
{
	t_win_list				*win;
	int						i;
	XSetWindowAttributes	xwa;

	win = xvar->win_list;
	while (win)
	{
		xwa.event_mask = 0;
		i = MLX_MAX_EVENT;
		while (i--)
			xwa.event_mask |= win->hooks[i].mask;
		XChangeWindowAttributes(xvar->display, win->window, CWEventMask, &xwa);
		win = win->next;
	}
}
