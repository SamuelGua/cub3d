/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:23:07 by scely             #+#    #+#             */
/*   Updated: 2024/05/30 21:20:02 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx.adrr + (y * data->mlx.l_length + x * (data->mlx.bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_texture_color(void *img, int tex_x, int tex_y)
{
	char	*pixel;
	int		color;
	int		bpp;
	int		line_length;

	pixel = mlx_get_data_addr(img, &bpp, &line_length, &color);
	pixel += tex_y * line_length + tex_x * (bpp / 8);
	color = *(unsigned int *)pixel;
	return (color);
}

int	castray(t_data *data)
{
	t_rutils	utils;

	utils.x = -1;
	data->mlx.img = mlx_new_image(data->mlx.ptr, SCREEN_W, SCREEN_H);
	if (!data->mlx.img)
		return (1);
	data->mlx.adrr = mlx_get_data_addr(data->mlx.img, &data->mlx.bpp,
			&data->mlx.l_length, &data->mlx.endian);
	if (!data->mlx.adrr)
	{
		mlx_destroy_image(data->mlx.ptr, data->mlx.img);
		return (1);
	}
	cast_floor(data);
	while (++utils.x < SCREEN_W)
	{
		set_value_init(&utils, data);
		setp_sidedist(&utils, data);
		dda_calcul(&utils, data);
		distanceview(&utils, data);
		(set_textures(&utils, data), draw_all(&utils, data));
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mlx.img, 0, 0);
	mlx_destroy_image(data->mlx.ptr, data->mlx.img);
	return (0);
}
