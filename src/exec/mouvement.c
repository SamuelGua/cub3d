/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:37:13 by scely             #+#    #+#             */
/*   Updated: 2024/05/29 12:22:52 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void key_w(t_data *data)
{
	double new_posx;
	double new_posy;

	new_posx = data->ray.pos_x + data->ray.dir_x * MOVE_SPEED;
	new_posy = data->ray.pos_y + data->ray.dir_y * MOVE_SPEED;
	if (data->pars.maps[(int)new_posx][(int)data->ray.pos_y] != '1')
		data->ray.pos_x = new_posx;
	if (data->pars.maps[(int)data->ray.pos_x][(int)new_posy] != '1')
		data->ray.pos_y = new_posy;
}

void key_s(t_data *data)
{
	double new_posx;
	double new_posy;

	new_posx = data->ray.pos_x - data->ray.dir_x * MOVE_SPEED;
	new_posy = data->ray.pos_y - data->ray.dir_y * MOVE_SPEED;
	if (data->pars.maps[(int)new_posx][(int)data->ray.pos_y] != '1')
		data->ray.pos_x = new_posx;
	if (data->pars.maps[(int)data->ray.pos_x][(int)new_posy] != '1')
		data->ray.pos_y = new_posy;
}

void key_d(t_data *data)
{
	double new_posx;
	double new_posy;

	new_posx = data->ray.pos_x - data->ray.dir_y * MOVE_SPEED;
	new_posy = data->ray.pos_y + data->ray.dir_x * MOVE_SPEED;
	if (data->pars.maps[(int)new_posx][(int)data->ray.pos_y] != '1')
		data->ray.pos_x = new_posx;
	if (data->pars.maps[(int)data->ray.pos_x][(int)new_posy] != '1')
		data->ray.pos_y = new_posy;
}

void key_a(t_data *data)
{
	double new_posx;
	double new_posy;

	new_posx = data->ray.pos_x + data->ray.dir_y * MOVE_SPEED;
	new_posy = data->ray.pos_y - data->ray.dir_x * MOVE_SPEED;
	if (data->pars.maps[(int)new_posx][(int)data->ray.pos_y] != '1')
		data->ray.pos_x = new_posx;
	if (data->pars.maps[(int)data->ray.pos_x][(int)new_posy] != '1')
		data->ray.pos_y = new_posy;
}

void	made_mouv(t_data *data, int keycode)
{
	printf("RAY_DIR_x = %f\n", data->ray.dir_x);
	printf("RAY_DIR_Y = %f\n", data->ray.dir_y); 
	printf("POS_X = %f\n", data->ray.pos_x); 
	printf("POS_Y = %f\n", data->ray.pos_y); 
	if (keycode != KEY_A && keycode != KEY_S && keycode != KEY_W
		&& keycode != KEY_D && keycode != LEFT && keycode != RIGHT)
		return ;	
	if (keycode == KEY_W)
		key_w(data);
	else if (keycode == KEY_S)
		key_s(data);
	if (keycode == KEY_D)
		key_d(data);
	else if (keycode == KEY_A)
		key_a(data);
	if (keycode == LEFT)
		rotate_left(data);
	if (keycode == RIGHT)
		rotate_right(data);
}
