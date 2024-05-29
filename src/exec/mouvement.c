/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:37:13 by scely             #+#    #+#             */
/*   Updated: 2024/05/29 10:09:06 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_data *data, int keycode)
{
	double	old_dirx;
	double	old_planex;

	if (keycode == LEFT)
	{
		old_dirx = data->ray.dir_x;
		data->ray.dir_x = data->ray.dir_x * cos(-ROT_SPEED) - data->ray.dir_y
			* sin(-ROT_SPEED);
		data->ray.dir_y = old_dirx * sin(-ROT_SPEED) + data->ray.dir_y
			* cos(-ROT_SPEED);
		old_planex = data->ray.plane_x;
		data->ray.plane_x = data->ray.plane_x * cos(-ROT_SPEED)
			- data->ray.plane_y * sin(-ROT_SPEED);
		data->ray.plane_y = old_planex * sin(-ROT_SPEED) + data->ray.plane_y
			* cos(-ROT_SPEED);
	}
	else if (keycode == RIGHT)
	{
		old_dirx = data->ray.dir_x;
		data->ray.dir_x = data->ray.dir_x * cos(ROT_SPEED) - data->ray.dir_y
			* sin(ROT_SPEED);
		data->ray.dir_y = old_dirx * sin(ROT_SPEED) + data->ray.dir_y
			* cos(ROT_SPEED);
		old_planex = data->ray.plane_x;
		data->ray.plane_x = data->ray.plane_x * cos(ROT_SPEED)
			- data->ray.plane_y * sin(ROT_SPEED);
		data->ray.plane_y = old_planex * sin(ROT_SPEED) + data->ray.plane_y
			* cos(ROT_SPEED);
	}
}

void	made_mouv(t_data *data, int keycode)
{
	printf("KEY_W = %c\n", data->pars.maps[(int)(data->ray.pos_x + data->ray.dir_x * MOVE_SPEED)][(int)data->ray.pos_y]);
	printf("KEY_D = %c\n", data->pars.maps[(int)data->ray.pos_x][(int)(data->ray.pos_y + data->ray.dir_y * MOVE_SPEED)]);
	printf("KEY_S = %c\n", data->pars.maps[(int)(data->ray.pos_x - data->ray.dir_x * MOVE_SPEED)][(int)data->ray.pos_y]);
	printf("KEY_A = %c\n", data->pars.maps[(int)data->ray.pos_x][(int)(data->ray.pos_y - data->ray.dir_y * MOVE_SPEED)]);
	printf("RAY_DIR_x = %f\n", data->ray.dir_x);
	printf("RAY_DIR_Y = %f\n", data->ray.dir_y);

	if (data->pars.maps[(int)data->ray.pos_x][(int)data->ray.pos_y] == 'N')
		data->pars.maps[(int)data->ray.pos_x][(int)data->ray.pos_y] = '0';

	if (keycode == KEY_W && data->pars.maps[(int)(data->ray.pos_x + data->ray.dir_x * MOVE_SPEED)][(int)data->ray.pos_y] != '1')
	{
		data->ray.pos_x += data->ray.dir_x * MOVE_SPEED;
	}
	else if (keycode == KEY_D && data->pars.maps[(int)data->ray.pos_x][(int)(data->ray.pos_y + data->ray.dir_y * MOVE_SPEED)] != '1')
	{
		data->ray.pos_y += data->ray.dir_y * MOVE_SPEED;
	}
	else if (keycode == KEY_S && data->pars.maps[(int)(data->ray.pos_x - data->ray.dir_x * MOVE_SPEED)][(int)data->ray.pos_y] != '1')
	{
		data->ray.pos_x -= data->ray.dir_x * MOVE_SPEED;
	}
	else if (keycode == KEY_A && data->pars.maps[(int)data->ray.pos_x][(int)(data->ray.pos_y - data->ray.dir_y * MOVE_SPEED)] != '1')
	{
		data->ray.pos_y -= data->ray.dir_y * MOVE_SPEED;
	}
	rotate(data, keycode);
}
