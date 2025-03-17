/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 01:59:17 by thzeribi          #+#    #+#             */
/*   Updated: 2022/07/26 06:20:59 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "peerclass.h"

//Get ramdom color in hexa format (0xFFFFFF)
int		get_random_color(void)
{
	int		color;
	int		r;
	int		g;
	int		b;
	
	color = 0;
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;
	color = r << 16 | g << 8 | b;
	return (color);
}

int
	game_loop(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < W)
	{
		while (x < H)
		{
			mlx_pixel_put(data->mlx.mlx, data->mlx.win, x, y, get_random_color());
			x++;
		}
		x = 0;
		y++;
	}
	return (TRUE);
}

int	main(void)
{
	t_data	data;

	data = (t_data){0};
	if (!_init_mlx(&data) || !_init_img(&data))
		exit_init(&data);
	mlx_loop_hook(data.mlx.mlx, game_loop, &data);
	mlx_loop(data.mlx.mlx);
	_end_mlx(&data);
	return (0);
}
