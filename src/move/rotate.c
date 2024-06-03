/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:15:45 by scely             #+#    #+#             */
/*   Updated: 2024/06/03 18:54:25 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_data *data)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->ray.dir_x;
	data->ray.dir_x = data->ray.dir_x * cos(-ROT_SPEED) - data->ray.dir_y
		* sin(-ROT_SPEED);
	data->ray.dir_y = old_dirx * sin(-ROT_SPEED) + data->ray.dir_y
		* cos(-ROT_SPEED);
	old_planex = data->ray.plane_x;
	data->ray.plane_x = data->ray.plane_x * cos(-ROT_SPEED) - data->ray.plane_y
		* sin(-ROT_SPEED);
	data->ray.plane_y = old_planex * sin(-ROT_SPEED) + data->ray.plane_y
		* cos(-ROT_SPEED);
}

void	rotate_right(t_data *data)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->ray.dir_x;
	data->ray.dir_x = data->ray.dir_x * cos(ROT_SPEED) - data->ray.dir_y
		* sin(ROT_SPEED);
	data->ray.dir_y = old_dirx * sin(ROT_SPEED) + data->ray.dir_y
		* cos(ROT_SPEED);
	old_planex = data->ray.plane_x;
	data->ray.plane_x = data->ray.plane_x * cos(ROT_SPEED) - data->ray.plane_y
		* sin(ROT_SPEED);
	data->ray.plane_y = old_planex * sin(ROT_SPEED) + data->ray.plane_y
		* cos(ROT_SPEED);
}
