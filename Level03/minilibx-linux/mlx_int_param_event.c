/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_param_event.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlie Root <ol@epitech.net>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/07/31 16:37:50 by Charlie Root      #+#    #+#             */
/*   Updated: 2021/10/26 16:58:42 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

static void	mlx_int_param_undef(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	(void)xvar;
	(void)ev;
	(void)win;
}

static void	mlx_int_param_keypress(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	win->hooks[KeyPress].hook(XkbKeycodeToKeysym(xvar->display,
			ev->xkey.keycode, 0, 0), win->hooks[KeyPress].param);
}

static void	mlx_int_param_keyrelease(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	win->hooks[KeyRelease].hook(XkbKeycodeToKeysym(xvar->display,
			ev->xkey.keycode, 0, 0), win->hooks[KeyRelease].param);
}

static void	mlx_int_param_buttonpress(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	(void)xvar;
	win->hooks[ButtonPress].hook(ev->xbutton.button, ev->xbutton.x,
		ev->xbutton.y, win->hooks[ButtonPress].param);
}

static void	mlx_int_param_buttonrelease(t_xvar *xvar, XEvent *ev,
	t_win_list *win)
{
	(void)xvar;
	win->hooks[ButtonRelease].hook(ev->xbutton.button, ev->xbutton.x,
		ev->xbutton.y, win->hooks[ButtonRelease].param);
}

static void	mlx_int_param_motionnotify(t_xvar *xvar, XEvent *ev,
	t_win_list *win)
{
	(void)xvar;
	win->hooks[MotionNotify].hook(ev->xbutton.x, ev->xbutton.y,
		win->hooks[MotionNotify].param);
}

static void	mlx_int_param_expose(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	(void)xvar;
	if (!ev->xexpose.count)
		win->hooks[Expose].hook(win->hooks[Expose].param);
}

static void	mlx_int_param_generic(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	(void)xvar;
	win->hooks[ev->type].hook(win->hooks[ev->type].param);
}

void	(*(mlx_int_param_event[]))() =
{
	mlx_int_param_undef,
	mlx_int_param_undef,
	mlx_int_param_keypress,
	mlx_int_param_keyrelease,
	mlx_int_param_buttonpress,
	mlx_int_param_buttonrelease,
	mlx_int_param_motionnotify,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_expose,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic
};
