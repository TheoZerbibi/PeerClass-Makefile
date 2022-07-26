/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 05:33:14 by thzeribi          #+#    #+#             */
/*   Updated: 2022/07/26 06:19:57 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "peerclass.h"

/**
** @name init_img()
** @brief Call by main function, this function init the img used
** to render fractol set later.
**
** @param t_data *data
** @return TRUE [1]
** @return FALSE [0]
**/
int
	_init_img(t_data *data)
{
	data->image.image = mlx_new_image(data->mlx.mlx, W, H);
	if (!data->image.image)
		return (FALSE);
	data->image.data = mlx_get_data_addr(data->image.image, &data->image.bpp,
		&data->image.size_line, &data->image.endian);
	if (!data->image.data)
		return (FALSE);
	return (TRUE);
}

/**
** @name init_fractol()
** @brief Call by main function, this function init mlx lib
** and all dependencies
**
** @param t_data *data
** @return TRUE [1]
** @return FALSE [0]
**/
int
	_init_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return (FALSE);
	data->mlx.win = mlx_new_window(data->mlx.mlx, H, W, TITLE);
	if (!data->mlx.win)
		return (FALSE);
	setup_hook(data);
	return (TRUE);
}