/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:17:45 by scely             #+#    #+#             */
/*   Updated: 2024/05/26 19:52:46 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//struture temporaire
#define NORD 1
#define SUD 2
#define EST 3
#define WEST 4

char *maps[] = {
	"1111111111",
	"1N00000001",
	"1010101001",
	"1000000101",
	"1111011111",
	"1010000001",
	"1001000001",
	"1000100001",
	"1000001001",
	"1111111111",
};

void init_data(t_data *data)
{
	// CHANGER LES SPIRTES
	data->pars.EA = ft_strdup("src/sprites/aloy.webp");
	data->pars.NO = ft_strdup("src/sprites/bayek.webp");
	data->pars.SO = ft_strdup("src/sprites/ichigo.webp");
	data->pars.WE = ft_strdup("src/sprites/sharigan.webp");

	data->pars.floor[0] = 0; data->pars.floor[1] = 0; data->pars.floor[2] = 0;
	data->pars.ciel[0] = 255; data->pars.ciel[1] = 255; data->pars.ciel[2] = 255;

	data->pars.maps = maps;

	data->ray.dir_x = -1;
	data->ray.dir_y = 0;

	data->ray.pos_x = 1;
	data->ray.pos_y = 1;

	data->ray.plane_x = 0;
	data->ray.plane_y = 0.66;
}

int	close_window(t_data *data)
{
	//free all
	(void)data;
	exit(1);
}
int	key_capt(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	return (0);
}

int	main(int ac, char *av[])
{
	(void)av;
	(void)ac;
	// si ac != 2 || ERROR NO MAPS;
	t_data data;
	init_data(&data);
	data.mlx.ptr = mlx_init();
	// proteger et free || error fail to init mlx;
	// checker si les images sont bonnes;
	
	data.mlx.win = mlx_new_window(data.mlx.ptr, 500, 500, "CUD3D");
	// proteger et free || error fail to creat windows;
	//===================================TEST RAYCAST================================
	// 1
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

	int r = 10;
	while (r--)
	{
		int x = -1;
		while (++x < SCREEN_W)
		{
			// 1 ray posittion and direction
			camera_x = 2 * x / (double)SCREEN_W - 1;
			raydir_x = data.ray.dir_x + data.ray.plane_x * camera_x;
			raydir_y = data.ray.dir_y + data.ray.plane_y * camera_x;

			// 2 part
			map_x = (int)data.ray.pos_x; 
			map_y = (int)data.ray.pos_y;
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
				side_distx = (data.ray.pos_x - map_x) * delta_distx;
			}
			else
			{
				step_x = 1;
				side_distx = (map_x + 1.0 - data.ray.pos_x) * delta_distx;
			}
			if (raydir_y < 0)
			{
				step_y = -1;
				side_disty = (data.ray.pos_y - map_y) * delta_disty;
			}
			else
			{
				step_y = 1;
				side_disty = (map_y + 1.0 - data.ray.pos_y) * delta_disty;
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
				if (data.pars.maps[map_x][map_y] == '1')
					hit = 1;
			}
			if (side == 0)
			{
				//perpwall_dist = side_distx - delta_distx;
				perpwall_dist = (map_x - data.ray.pos_x + (1 - step_x) / 2) / raydir_x;

			}
			else
			{
				// perpwall_dist = side_disty - delta_disty;
				perpwall_dist = (map_y - data.ray.pos_y + (1 - step_y) / 2) / raydir_y;

			}
			
			// 3
			line_height = (int)SCREEN_H / perpwall_dist;
			draw_start = -line_height /2 + SCREEN_H / 2;
			if (draw_start < 0)
				draw_start = 0;
			draw_end = line_height / 2 + SCREEN_H / 2;
			if (draw_end >= SCREEN_H)
				draw_end = SCREEN_H - 1;

		}
		for (int y = draw_start; y < draw_end; y++)
		{
		
			mlx_pixel_put(data.mlx.ptr, data.mlx.win, x, y, 0x00FF00);
			printf("start = %d | end = %d\n", draw_start, draw_end);
		}
	}

	//===============================================================================
	mlx_hook(data.mlx.win, 2, 1L << 0, key_capt, &data);

	mlx_hook(data.mlx.win, 17, 1L << 17, close_window, &data);
	mlx_loop(data.mlx.ptr);

}
