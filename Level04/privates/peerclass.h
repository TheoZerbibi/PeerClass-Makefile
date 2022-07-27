/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peerclass.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 01:58:06 by thzeribi          #+#    #+#             */
/*   Updated: 2022/07/27 13:50:37 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEERCLASS_H
# define PEERCLASS_H

# define H	1500
# define W	1300
# define TITLE "PeerClass"

# define STR "Hello Peerclass Level4 !\n"

# include <stdio.h>
# include <unistd.h>

# include "libft.h"
# include "struct.h"
# include "mlx.h"

int		_init_img(t_data *data);
int		_init_mlx(t_data *data);
int		_end_mlx(t_data *data);

void	setup_hook(t_data *data);
int		keypress(int keycode, t_data *datafractol);
int		zoom(int keycode, t_data *data);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

void	exit_init(t_data *data);

#endif