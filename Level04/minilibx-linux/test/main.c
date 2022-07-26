/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 00:26:02 by anclarma          #+#    #+#             */
/*   Updated: 2021/10/27 05:13:05 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_int.h"

#define WIN1_SX		242
#define WIN1_SY		242
#define IM1_SX		42
#define IM1_SY		42
#define IM3_SX		242
#define IM3_SY		242

typedef struct s_mlx    t_mlx;
struct  s_mlx
{
	t_xvar	*mlx_ptr;
	void	*win1;
	void	*win2;
	void	*win3;
	t_img	*im1;
	t_img	*im2;
	t_img	*im3;
	t_img	*im4;
	char	*data1;
	char	*data2;
	char	*data3;
	char	*data4;
};

int		bpp1;
int		bpp2;
int		bpp3;
int		bpp4;
int		sl1;
int		sl2;
int		sl3;
int		sl4;
int		endian1;
int		endian2;
int		endian3;
int		endian4;
int		xpm1_x;
int		xpm1_y;

int		local_endian;

static void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = (void *)0;
	mlx->win1 = (void *)0;
	mlx->win2 = (void *)0;
	mlx->win3 = (void *)0;
	mlx->im1 = (void *)0;
	mlx->im2 = (void *)0;
	mlx->im3 = (void *)0;
	mlx->im4 = (void *)0;
	mlx->data1 = (void *)0;
	mlx->data2 = (void *)0;
	mlx->data3 = (void *)0;
	mlx->data4 = (void *)0;
}

static void	clean_mlx(t_mlx *mlx)
{
	if (mlx->im4)
		mlx_destroy_image(mlx->mlx_ptr, mlx->im4);
	if (mlx->im3)
		mlx_destroy_image(mlx->mlx_ptr, mlx->im3);
	if (mlx->im2)
		mlx_destroy_image(mlx->mlx_ptr, mlx->im2);
	if (mlx->im1)
		mlx_destroy_image(mlx->mlx_ptr, mlx->im1);
	if (mlx->win3)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win3);
	if (mlx->win2)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win2);
	if (mlx->win1)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win1);
	if (mlx->mlx_ptr)
		mlx_destroy_display(mlx->mlx_ptr);
}

static void	color_map_1(t_mlx *mlx, void *win, int w, int h)
{
	int	x;
	int	y;
	int	color;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)
		{
			color = (x * 255) / w + ((((w - x) * 255) / w) << 16)
				+ (((y * 255) / h) << 8);
			mlx_pixel_put(mlx->mlx_ptr, win, x, y, color);
		}
	}
}

static void	color_map_2(t_mlx *mlx, char *data, int bpp, int sl, int w, int h, int endian,
	int type)
{
	int				x;
	int				y;
	int				opp;
	int				dec;
	int				color;
	int				color2;
	unsigned char	*ptr;

	opp = bpp / 8;
	printf("(opp : %d) ", opp);
	y = h;
	while (y--)
	{
		ptr = (unsigned char *)data + y * sl;
		x = w;
		while (x--)
		{
			if (type == 2)
				color = (y * 255) / w + ((((w - x) * 255) / w) << 16)
					+ (((y * 255) / h) << 8);
			else
				color = (x * 255) / w + ((((w - x) * 255) / w) << 16)
					+ (((y * 255) / h) << 8);
			color2 = mlx_get_color_value(mlx->mlx_ptr, color);
			dec = opp;
			while (dec--)
			{
				if (endian == local_endian)
				{
					if (endian)
						*(ptr + x * opp + dec)
							= ((unsigned char *)(&color2))[4 - opp + dec];
					else
						*(ptr + x * opp + dec)
							= ((unsigned char *)(&color2))[dec];
				}
				else
				{
					if (endian)
						*(ptr + x * opp + dec)
							= ((unsigned char *)(&color2))[opp - 1 - dec];
					else
						*(ptr + x * opp + dec)
							= ((unsigned char *)(&color2))[3 - dec];
				}
			}
		}
	}
}

static int	no_event(void *p)
{
	(void)p;
	return (0);
}

static int	expose_win1(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win1, mlx->im3, 0, 0);
	return (0);
}

static int	expose_win2( t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win2, mlx->im4, 0, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win2, mlx->im2, 0, 0);
	return (0);
}

static int	key_win1(int key, t_mlx *mlx)
{
	printf("Key in Win1 : %d\n", key);
	if (key == 0xFF1B)
		mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

static int	key_win2(int key, t_mlx *mlx)
{
	printf("Key in Win2 : %d\n", key);
	if (key == 0xFF1B)
		mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

static int	key_win3(int key, t_mlx *mlx)
{
	printf("Key in Win3 : %d\n", key);
	if (key == 0xFF1B && mlx->win3)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win3);
		mlx->win3 = (void *)0;
	}
	return (0);
}

static int	mouse_win1(int button, int x, int y, void *p)
{
	(void)p;
	printf("Mouse in Win1, button %d at %dx%d.\n", button, x, y);
	return (0);
}

static int	mouse_win2(int button, int x, int y, void *p)
{
	(void)p;
	printf("Mouse in Win2, button %d at %dx%d.\n", button, x, y);
	return (0);
}

static int	mouse_win3(int x, int y, void *p)
{
	(void)p;
	printf("Mouse moving in Win3, at %dx%d.\n", x, y);
	return (0);
}

int	main(void)
{
	int		a;
	t_mlx	mlx;

	init_mlx(&mlx);
	printf("MinilibX Test Program\n");
	a = 0x11223344;
	if (((unsigned char *)&a)[0] == 0x11)
		local_endian = 1;
	else
		local_endian = 0;
	printf(" => Local Endian : %d\n", local_endian);
	printf(" => Connection ...");
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
	{
		printf(" !! KO !!\n");
		clean_mlx(&mlx);
		return (1);
	}
	printf("OK (use_xshm %d pshm_format %d)\n", mlx.mlx_ptr->use_xshm,
		mlx.mlx_ptr->pshm_format);
	printf(" => Window1 %dx%d \"Title 1\" ...", WIN1_SX, WIN1_SY);
	mlx.win1 = mlx_new_window(mlx.mlx_ptr, WIN1_SX, WIN1_SY, "Title1");
	if (!mlx.win1)
	{
		printf(" !! KO !!\n");
		clean_mlx(&mlx);
		return (1);
	}
	printf("OK\n");
	printf(" => Colormap sans event ...");
	color_map_1(&mlx, mlx.win1, WIN1_SX, WIN1_SY);
	printf("OK\n");
	sleep(2);
	printf(" => Clear Window ...");
	mlx_clear_window(mlx.mlx_ptr, mlx.win1);
	printf("OK\n");
	sleep(2);
	printf(" => Image1 ZPixmap %dx%d ...", IM1_SX, IM1_SY);
	mlx.im1 = mlx_new_image(mlx.mlx_ptr, IM1_SX, IM1_SY);
	if (!mlx.im1)
	{
		printf(" !! KO !!\n");
		clean_mlx(&mlx);
		return (1);
	}
	mlx.data1 = mlx_get_data_addr(mlx.im1, &bpp1, &sl1, &endian1);
	printf("OK (bpp1: %d, sizeline1: %d endian: %d type: %d)\n",
		bpp1, sl1, endian1, mlx.im1->type);
	printf(" => Fill Image1 ...");
	color_map_2(&mlx, mlx.data1, bpp1, sl1, IM1_SX, IM1_SY, endian1, 1);
	printf("OK (pixmap : %d)\n", (int)mlx.im1->pix);
	printf(" => Put Image1 ...");
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win1, mlx.im1, 20, 20);
	printf("OK\n");
	sleep(2);
	printf(" => Destroy Image1 ... ");
	mlx_destroy_image(mlx.mlx_ptr, mlx.im1);
	mlx.im1 = (void *)0;
	printf("OK\n");
	sleep(2);
	printf(" => Image3 ZPixmap %dx%d ...", IM3_SX, IM3_SY);
	mlx.im3 = mlx_new_image(mlx.mlx_ptr, IM3_SX, IM3_SY);
	if (!mlx.im3)
	{
		printf(" !! KO !!\n");
		clean_mlx(&mlx);
		return (1);
	}
	mlx.data3 = mlx_get_data_addr(mlx.im3, &bpp3, &sl3, &endian3);
	printf("OK (bpp3 %d, sizeline3 %d endian3 %d type %d)\n",
		bpp3, sl3, endian3, mlx.im3->type);
	printf(" => Fill Image3 ...");
	color_map_2(&mlx, mlx.data3, bpp3, sl3, IM3_SX, IM3_SY, endian3, 1);
	printf("OK (pixmap : %d)\n", (int)mlx.im3->pix);
	printf(" => Put Image3 ...");
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win1, mlx.im3, 20, 20);
	printf("OK\n");
	sleep(2);
	printf(" => String ...");
	mlx_string_put(mlx.mlx_ptr, mlx.win1, 5, WIN1_SY / 2, 0xFF99FF, "String output");
	mlx_string_put(mlx.mlx_ptr, mlx.win1, 15, WIN1_SY / 2 + 20, 0x00FFFF, "MinilibX test");
	printf("OK\n");
	sleep(2);
	printf(" => Xpm from file ...");
	mlx.im2 = mlx_xpm_file_to_image(mlx.mlx_ptr, "open.xpm", &xpm1_x, &xpm1_y);
	if (!mlx.im2)
	{
		printf(" !! KO !!\n");
		clean_mlx(&mlx);
		return (1);
	}
	mlx.data2 = mlx_get_data_addr(mlx.im2, &bpp2, &sl2, &endian2);
	printf("OK (xpm %dx%d)(img bpp2: %d, sizeline2: %d endian: %d type: %d)\n",
		xpm1_x, xpm1_y, bpp2, sl2, endian2, mlx.im2->type);
	sleep(2);
	printf(" => Put xpm ...");
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win1, mlx.im2, 0, 0);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win1, mlx.im2, 100, 100);
	printf("OK\n");
	sleep(2);
	printf(" => 2nd window,");
	mlx.win2 = mlx_new_window(mlx.mlx_ptr, WIN1_SX, WIN1_SY, "Title2");
	if (!mlx.win2)
	{
		printf(" !! KO !!\n");
		clean_mlx(&mlx);
		return (1);
	}
	mlx.im4 = mlx_new_image(mlx.mlx_ptr, IM3_SX, IM3_SY);
	if (!mlx.im4)
	{
		printf(" !! KO !!\n");
		clean_mlx(&mlx);
		return (1);
	}
	mlx.data4 = mlx_get_data_addr(mlx.im4, &bpp4, &sl4, &endian4);
	color_map_2(&mlx, mlx.data4, bpp4, sl4, IM3_SX, IM3_SY, endian4, 2);
	printf(" 3rd window, Installing hooks ...");
	mlx.win3 = mlx_new_window(mlx.mlx_ptr, WIN1_SX, WIN1_SY, "Title3");
	mlx_loop_hook(mlx.mlx_ptr, no_event, &mlx);
	mlx_expose_hook(mlx.win1, expose_win1, &mlx);
	mlx_mouse_hook(mlx.win1, mouse_win1, &mlx);
	mlx_key_hook(mlx.win1, key_win1, &mlx);
	mlx_expose_hook(mlx.win2, expose_win2, &mlx);
	mlx_mouse_hook(mlx.win2, mouse_win2, &mlx);
	mlx_key_hook(mlx.win2, key_win2, &mlx);
	mlx_key_hook(mlx.win3, key_win3, &mlx);
	mlx_hook(mlx.win3, MotionNotify, PointerMotionMask, mouse_win3, &mlx);
	printf("OK\nNow in Loop. Just play. Esc in 3 to destroy, 1&2 to quit.\n");
	mlx_loop(mlx.mlx_ptr);
	clean_mlx(&mlx);
	return (0);
}
