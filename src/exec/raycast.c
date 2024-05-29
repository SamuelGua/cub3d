/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:23:07 by scely             #+#    #+#             */
/*   Updated: 2024/05/29 12:25:43 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx.adrr + (y * data->mlx.l_length + x * (data->mlx.bpp / 8));
	*(unsigned int*)dst = color;
}

void castray(t_data *data)
{	// 1
	double camera_x;
	double raydir_x;
	double raydir_y;
	
	// 2
	int map_x;
	int map_y;
	double side_distx;
	double side_disty;
	double delta_distx;
	double delta_disty;
	double perpwall_dist;
	int step_x;
	int step_y;
	int hit;
	int side;
	//3
	int line_height;
	int draw_start;
	int draw_end;

	int x = -1;
	// if (data->mlx.img)
	// 	mlx_destroy_image(data->mlx.ptr, data->mlx.img);
	data->mlx.img = mlx_new_image(data->mlx.ptr, SCREEN_W, SCREEN_H);
	data->mlx.adrr = mlx_get_data_addr(data->mlx.img, &data->mlx.bpp, &data->mlx.l_length, &data->mlx.endian);

	while (++x < SCREEN_W)
	{
		// 1 ray posittion and direction
		camera_x = 2 * x / (double)SCREEN_W - 1;
		raydir_x = data->ray.dir_x + data->ray.plane_x * camera_x;
		raydir_y = data->ray.dir_y + data->ray.plane_y * camera_x;

		// 2 part
		map_x = (int)data->ray.pos_x; 
		map_y = (int)data->ray.pos_y;
		if (raydir_x == 0)
			delta_distx = 1e30;
		else
			delta_distx = fabs(1 / raydir_x);
		if (raydir_y == 0)
			delta_disty = 1e30;
		else
			delta_disty = fabs(1 / raydir_y);
		
		if (raydir_x < 0)
		{
			step_x = -1;
			side_distx = (data->ray.pos_x - map_x) * delta_distx;
		}
		else
		{
			step_x = 1;
			side_distx = (map_x + 1.0 - data->ray.pos_x) * delta_distx;
		}
		if (raydir_y < 0)
		{
			step_y = -1;
			side_disty = (data->ray.pos_y - map_y) * delta_disty;
		}
		else
		{
			step_y = 1;
			side_disty = (map_y + 1.0 - data->ray.pos_y) * delta_disty;
		}

		//verifier que le x et les y sont bons
		hit = 0;
		while (hit == 0)
		{
			if (side_distx < side_disty)
			{
				side_distx += delta_distx;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_disty += delta_disty;
				map_y += step_y;
				side = 1;
			}
			if (data->pars.maps[map_x][map_y] == '1'
				|| data->pars.maps[map_x][map_y] == '2')
				hit = 1;
		}
		if (side == 0)
		{
			// perpwall_dist = side_distx - delta_distx;
			perpwall_dist = (map_x - data->ray.pos_x + (1 - step_x) / 2) / raydir_x;
		}
		else
		{
			// perpwall_dist = side_disty - delta_disty;
			perpwall_dist = (map_y - data->ray.pos_y + (1 - step_y) / 2) / raydir_y;
		}
		// 3
		line_height = (int)SCREEN_H / perpwall_dist;
		draw_start = -line_height /2 + SCREEN_H / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + SCREEN_H / 2;
		if (draw_end >= SCREEN_H)
			draw_end = SCREEN_H - 1;


		int color = 0xFF00FF;
		for (int y = draw_start; y < draw_end; y++)
		{	
			// mlx_pixel_put(data->mlx.ptr, data->mlx.win, x, y, color);
			my_mlx_pixel_put(data, x, y, color);
		}
		mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mlx.img, 0, 0);
	}
		mlx_destroy_image(data->mlx.ptr, data->mlx.img);
}