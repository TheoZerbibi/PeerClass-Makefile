/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 05:37:57 by thzeribi          #+#    #+#             */
/*   Updated: 2022/07/26 06:00:03 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "peerclass.h"

/**
** @name keypress();
** @brief Call when key is pressed. This function is init
** by mlx_key_hook() from MLX Lib in setup_hook() function.
**
** @param int keycode
** @param t_data *fractol
** @return keycode
**/
int
	keypress(int keycode, t_data *data)
{
	// printf("key code : %d\n", keycode);
	if (keycode == 65307)
		_end_mlx(data);
	return (keycode);
}