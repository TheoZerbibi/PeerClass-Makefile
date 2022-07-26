/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 05:35:19 by thzeribi          #+#    #+#             */
/*   Updated: 2022/07/26 06:00:03 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "peerclass.h"

/**
** @name setup_hook();
** @brief Call by init_fractol() function. This function init all hook event.
**
** @param t_data *data
**/
void
	setup_hook(t_data *data)
{
	mlx_key_hook(data->mlx.win, keypress, data);
	mlx_hook(data->mlx.win, 33, 1L << 17, _end_mlx, data);
	mlx_mouse_hook(data->mlx.win, &zoom, data);
}