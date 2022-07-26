/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlie Root <ol@epitech.net>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/08/03 11:49:06 by Charlie Root      #+#    #+#             */
/*   Updated: 2021/11/01 13:39:38 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void	mlx_loop_hook(t_xvar *xvar, int (*funct)(), void *param)
{
	xvar->loop_hook = funct;
	xvar->loop_param = param;
}
