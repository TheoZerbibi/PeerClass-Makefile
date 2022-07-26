/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlie Root <ol@epitech.net>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/07/03 11:49:06 by Charlie Root      #+#    #+#             */
/*   Updated: 2021/10/26 02:05:32 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void	mlx_hook(t_win_list *win, int x_event, int x_mask,
	int (*funct)(), void *param)
{
	win->hooks[x_event].hook = funct;
	win->hooks[x_event].param = param;
	win->hooks[x_event].mask = x_mask;
}

void	mlx_do_key_autorepeatoff(t_xvar *xvar)
{
	XAutoRepeatOff(xvar->display);
}

void	mlx_do_key_autorepeaton(t_xvar *xvar)
{
	XAutoRepeatOn(xvar->display);
}

void	mlx_do_sync(t_xvar *xvar)
{
	XSync(xvar->display, False);
}
