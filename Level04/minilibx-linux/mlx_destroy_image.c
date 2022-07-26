/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlie Root <ol@epitech.net>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2002/03/12 10:25:15 by Charlie Root      #+#    #+#             */
/*   Updated: 2021/10/18 00:15:40 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void	mlx_destroy_image(t_xvar *xvar, t_img *img)
{
	if (img->type == MLX_TYPE_SHM_PIXMAP || img->type == MLX_TYPE_SHM)
	{
		XShmDetach(xvar->display, &(img->shm));
		shmdt(img->shm.shmaddr);
	}
	XDestroyImage(img->image);
	XFreePixmap(xvar->display, img->pix);
	if (img->gc)
		XFreeGC(xvar->display, img->gc);
	free(img);
	if (xvar->do_flush)
		XFlush(xvar->display);
}
