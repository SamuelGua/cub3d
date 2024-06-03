/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:08:49 by scely             #+#    #+#             */
/*   Updated: 2024/06/03 18:43:58 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_value_init(t_rutils *utils, t_data *data)
{
	utils->camera_x = 2 * utils->x / (double)SCREEN_W - 1;
	utils->raydir_y = data->ray.dir_x + data->ray.plane_x * utils->camera_x;
	utils->raydir_x = data->ray.dir_y + data->ray.plane_y * utils->camera_x;
	utils->map_x = (int)data->ray.pos_x;
	utils->map_y = (int)data->ray.pos_y;
	if (utils->raydir_x == 0)
		utils->delta_distx = 1e30;
	else
		utils->delta_distx = fabs(1 / utils->raydir_x);
	if (utils->raydir_y == 0)
		utils->delta_disty = 1e30;
	else
		utils->delta_disty = fabs(1 / utils->raydir_y);
}

void	setp_sidedist(t_rutils *utils, t_data *data)
{
	if (utils->raydir_x < 0)
	{
		utils->step_x = -1;
		utils->side_distx = (data->ray.pos_x - utils->map_x)
			* utils->delta_distx;
	}
	else
	{
		utils->step_x = 1;
		utils->side_distx = (utils->map_x + 1.0 - data->ray.pos_x)
			* utils->delta_distx;
	}
	if (utils->raydir_y < 0)
	{
		utils->step_y = -1;
		utils->side_disty = (data->ray.pos_y - utils->map_y)
			* utils->delta_disty;
	}
	else
	{
		utils->step_y = 1;
		utils->side_disty = (utils->map_y + 1.0 - data->ray.pos_y)
			* utils->delta_disty;
	}
}

void	dda_calcul(t_rutils *utils, t_data *data)
{
	utils->hit = 0;
	while (utils->hit == 0)
	{
		if (utils->side_distx < utils->side_disty)
		{
			utils->side_distx += utils->delta_distx;
			utils->map_x += utils->step_x;
			utils->side = 0;
		}
		else
		{
			utils->side_disty += utils->delta_disty;
			utils->map_y += utils->step_y;
			utils->side = 1;
		}
		if (data->pars.map[utils->map_x][utils->map_y] == '1'
			|| data->pars.map[utils->map_x][utils->map_y] == '2')
			utils->hit = 1;
	}
}
