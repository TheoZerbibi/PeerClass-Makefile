/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_data_addr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlie Root <ol@epitech.net>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/08/14 15:45:57 by Charlie Root      #+#    #+#             */
/*   Updated: 2021/11/01 14:15:24 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

char	*mlx_get_data_addr(t_img *img, int *bits_per_pixel,
	int *size_line, int *endian)
{
	*bits_per_pixel = img->bpp;
	*size_line = img->size_line;
	*endian = img->image->byte_order;
	return (img->data);
}
