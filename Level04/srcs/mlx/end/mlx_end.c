/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 05:41:02 by thzeribi          #+#    #+#             */
/*   Updated: 2022/07/26 06:11:12 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "peerclass.h"

/**
** @name init_fractol()
** @brief this function is called at the very end of the program. His goal
** is to free all allocated memory.
**
** @param t_data *fractol
** @return TRUE [1]
** @return FALSE [0]
**/
int
	_end_mlx(t_data *data)
{
	if (data->mlx.mlx)
	{
		if (data->mlx.win)
			mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		if (data->image.image)
			mlx_destroy_image(data->mlx.mlx, data->image.image);
		mlx_loop_end(data->mlx.mlx);
		mlx_destroy_display(data->mlx.mlx);
	}
	exit(0);
}