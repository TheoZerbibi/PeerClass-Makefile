/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_screen_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:40:40 by anclarma          #+#    #+#             */
/*   Updated: 2021/10/20 19:42:54 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey)
{
	XWindowAttributes	xw_attr;
	Status				ret;
	t_xvar				*xvar;

	xvar = mlx_ptr;
	ret = XGetWindowAttributes(xvar->display, xvar->root, &xw_attr);
	(void)ret;
	(*sizex) = xw_attr.width;
	(*sizey) = xw_attr.height;
}
