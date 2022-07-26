/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_anti_resize_win.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlie Root <ol@epitech.net>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/08/08 14:31:05 by Charlie Root      #+#    #+#             */
/*   Updated: 2021/10/21 17:14:49 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void	mlx_int_anti_resize_win(t_xvar *xvar, Window win, int w, int h)
{
	XSizeHints	hints;
	long int	toto;

	XGetWMNormalHints(xvar->display, win, &hints, &toto);
	hints.width = w;
	hints.height = h;
	hints.min_width = w;
	hints.min_height = h;
	hints.max_width = w;
	hints.max_height = h;
	hints.flags = PPosition | PSize | PMinSize | PMaxSize;
	XSetWMNormalHints(xvar->display, win, &hints);
}
