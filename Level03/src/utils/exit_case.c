/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 06:45:25 by thzeribi          #+#    #+#             */
/*   Updated: 2022/07/26 06:00:03 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "peerclass.h"

/**
** @name exit_init();
** @brief Call when initialisation failed.
**
** @param t_data *data
**/
void
	exit_init(t_data *data)
{
	fprintf(stderr, "\e[1;31mError during Initialisation !\e[0m\n");
	_end_mlx(data);
	exit(1);
}
