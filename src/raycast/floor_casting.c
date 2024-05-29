/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:58:57 by scely             #+#    #+#             */
/*   Updated: 2024/05/29 23:07:16 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int cast_floor(t_data *data)
{
	int y;
	int x;

	y = -1;
	while (++y <= SCREEN_H)
	{
		x = 0;
		// int color_f = 0xADD8E6;
		// int color_c = 0x654321;
		while (x < SCREEN_W - 1)
		{
			my_mlx_pixel_put(data, x, y, data->ray.floor);
			int c = SCREEN_H - y - 1;
			if (c >= 0)
				my_mlx_pixel_put(data, x, c, data->ray.ciel);
			x++;
		}
	}
	return (0);
}
