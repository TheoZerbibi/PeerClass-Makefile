/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_wait_first_expose.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier crouzet <ol@epita.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/10/17 09:26:45 by olivier crouzet   #+#    #+#             */
/*   Updated: 2021/10/21 00:59:12 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void	mlx_int_wait_first_expose(t_xvar *xvar, Window win)
{
	XEvent	ev;

	XWindowEvent(xvar->display, win, ExposureMask, &ev);
	XPutBackEvent(xvar->display, &ev);
}
