/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 05:56:37 by thzeribi          #+#    #+#             */
/*   Updated: 2022/07/26 05:56:48 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "mlx_int.h"

typedef struct s_mlx	t_mlx;
typedef struct s_data	t_data;

struct s_mlx
{
	void	*mlx;
	void	*win;
};

struct s_data
{
	t_mlx		mlx;
	t_img		image;
};


#endif