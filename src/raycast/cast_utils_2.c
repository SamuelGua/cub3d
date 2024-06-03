/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:08:49 by scely             #+#    #+#             */
/*   Updated: 2024/06/03 19:19:40 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	distanceview(t_rutils *utils, t_data *data)
{
	if (utils->side == 0)
		utils->perpwall_dist = (utils->map_x - data->ray.pos_x + (1
					- utils->step_x) / 2) / utils->raydir_x;
	else
		utils->perpwall_dist = (utils->map_y - data->ray.pos_y + (1
					- utils->step_y) / 2) / utils->raydir_y;
	utils->line_height = (int)SCREEN_H / utils->perpwall_dist;
	utils->draw_start = -utils->line_height / 2 + SCREEN_H / 2;
	if (utils->draw_start < 0)
		utils->draw_start = 0;
	utils->draw_end = utils->line_height / 2 + SCREEN_H / 2;
	if (utils->draw_end >= SCREEN_H)
		utils->draw_end = SCREEN_H - 1;
}

void	set_textures(t_rutils *utils, t_data *data)
{
	if (utils->side == 0)
	{
		if (utils->step_x > 0)
			utils->texture = data->mlx.img_so;
		else
			utils->texture = data->mlx.img_no;
	}
	else
	{
		if (utils->step_y > 0)
			utils->texture = data->mlx.img_ea;
		else
			utils->texture = data->mlx.img_we;
	}
}

void	draw_all(t_rutils *utils, t_data *data)
{
	if (utils->side == 0)
		utils->wallx = data->ray.pos_y + utils->perpwall_dist * utils->raydir_y;
	else
		utils->wallx = data->ray.pos_x + utils->perpwall_dist * utils->raydir_x;
	utils->wallx -= floor(utils->wallx);
	utils->tex_x = (int)(utils->wallx * IMG_W);
	if (utils->side == 0 && utils->raydir_x > 0)
		utils->tex_x = IMG_W - utils->tex_x - 1;
	if (utils->side == 1 && utils->raydir_y < 0)
		utils->tex_x = IMG_W - utils->tex_x - 1;
	utils->y = utils->draw_start;
	while (utils->y < utils->draw_end)
	{
		utils->d = utils->y * 256 - SCREEN_H * 128 + utils->line_height * 128;
		utils->tex_y = ((utils->d * IMG_H) / utils->line_height) / 256;
		utils->color = get_texture_color(utils->texture, utils->tex_x,
				utils->tex_y);
		my_mlx_pixel_put(data, utils->x, utils->y, utils->color);
		utils->y++;
	}
}
