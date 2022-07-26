/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlie Root <ol@epitech.net>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/08/03 11:49:06 by Charlie Root      #+#    #+#             */
/*   Updated: 2021/11/01 14:17:50 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void	mlx_key_hook(t_win_list *win, int (*funct)(), void *param)
{
	win->hooks[KeyRelease].hook = funct;
	win->hooks[KeyRelease].param = param;
	win->hooks[KeyRelease].mask = KeyReleaseMask;
}
