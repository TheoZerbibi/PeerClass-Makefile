/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlie Root <ol@epitech.net>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/08/14 15:29:14 by Charlie Root      #+#    #+#             */
/*   Updated: 2021/11/01 14:42:21 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

/*
** To handle X errors
*/

#define X_SHMATTACH	1

int	g_mlx_x_error;

static int	shm_att_pb(Display *d, XErrorEvent *ev)
{
	ssize_t	ret;

	(void)d;
	if (ev->request_code == 146 && ev->minor_code == X_SHMATTACH)
		ret = write(2, WARN_SHM_ATTACH, strlen(WARN_SHM_ATTACH));
	(void)ret;
	g_mlx_x_error = 1;
	return (0);
}

/*
**  Data malloc :  width+32 ( bitmap_pad=32 ),    *4 = *32 / 8bit
*/

static void	*mlx_int_new_xshm_image(t_xvar *xvar,
	int width, int height, int format)
{
	t_img	*img;
	int		(*save_handler)();

	img = malloc(sizeof(*img));
	if (!img)
		return ((void *)0);
	bzero(img, sizeof(*img));
	img->data = 0;
	img->image = XShmCreateImage(xvar->display, xvar->visual, xvar->depth,
			format, img->data, &(img->shm), width, height);
	if (!img->image)
	{
		free(img);
		return ((void *)0);
	}
	img->width = width;
	img->height = height;
	img->size_line = img->image->bytes_per_line;
	img->bpp = img->image->bits_per_pixel;
	img->format = format;
	img->shm.shmid = shmget(IPC_PRIVATE, (width + 32) * height * 4,
			IPC_CREAT | 0777);
	if (img->shm.shmid == -1)
	{
		XDestroyImage(img->image);
		free(img);
		return ((void *)0);
	}
	img->image->data = shmat(img->shm.shmid, 0, 0);
	img->shm.shmaddr = img->image->data;
	img->data = img->image->data;
	if (img->data == (void *)-1)
	{
		shmctl(img->shm.shmid, IPC_RMID, 0);
		XDestroyImage(img->image);
		free(img);
		return ((void *)0);
	}
	img->shm.readOnly = False;
	g_mlx_x_error = 0;
	save_handler = XSetErrorHandler(shm_att_pb);
	if (!XShmAttach(xvar->display, &(img->shm))
		|| 0 & XSync(xvar->display, False) || g_mlx_x_error)
	{
		XSetErrorHandler(save_handler);
		shmdt(img->data);
		shmctl(img->shm.shmid, IPC_RMID, 0);
		XDestroyImage(img->image);
		free(img);
		return ((void *)0);
	}
	XSetErrorHandler(save_handler);
	shmctl(img->shm.shmid, IPC_RMID, 0);
	if (xvar->pshm_format == format)
	{
		img->pix = XShmCreatePixmap(xvar->display, xvar->root, img->shm.shmaddr,
				&(img->shm), width, height, xvar->depth);
		img->type = MLX_TYPE_SHM_PIXMAP;
	}
	else
	{
		img->pix = XCreatePixmap(xvar->display, xvar->root,
				width, height, xvar->depth);
		img->type = MLX_TYPE_SHM;
	}
	if (xvar->do_flush)
		XFlush(xvar->display);
	return (img);
}

static void	*mlx_int_new_image(t_xvar *xvar, int width, int height, int format)
{
	t_img	*img;

	img = malloc(sizeof(*img));
	if (!img)
		return ((void *)0);
	img->data = malloc((width + 32) * height * 4);
	if (!img->data)
	{
		free(img);
		return ((void *)0);
	}
	bzero(img->data, (width + 32) * height * 4);
	img->image = XCreateImage(xvar->display, xvar->visual, xvar->depth, format,
			0, img->data, width, height, 32, 0);
	if (!img->image)
	{
		free(img->data);
		free(img);
		return ((void *)0);
	}
	img->gc = 0;
	img->size_line = img->image->bytes_per_line;
	img->bpp = img->image->bits_per_pixel;
	img->width = width;
	img->height = height;
	img->pix = XCreatePixmap(xvar->display, xvar->root, width, height,
			xvar->depth);
	img->format = format;
	img->type = MLX_TYPE_XIMAGE;
	if (xvar->do_flush)
		XFlush(xvar->display);
	return (img);
}

void	*mlx_new_image(t_xvar *xvar, int width, int height)
{
	t_img	*img;

	if (xvar->use_xshm)
	{
		img = mlx_int_new_xshm_image(xvar, width, height, ZPixmap);
		if (img)
			return (img);
	}
	return (mlx_int_new_image(xvar, width, height, ZPixmap));
}

void	*mlx_new_image2(t_xvar *xvar, int width, int height)
{
	t_img	*img;

	if (xvar->use_xshm)
	{
		img = mlx_int_new_xshm_image(xvar, width, height, XYPixmap);
		if (img)
			return (img);
	}
	return (mlx_int_new_image(xvar, width, height, XYPixmap));
}
