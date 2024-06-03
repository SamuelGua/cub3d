/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:24:49 by scely             #+#    #+#             */
/*   Updated: 2024/06/03 19:45:13 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_get_screen_size(data->mlx.ptr, &j, &i);
	if (SCREEN_W >= j - 1 || SCREEN_H >= i - 1)
		return (printf("Error: Screen too small\n"), 1);
	data->mlx.img_ea = mlx_xpm_file_to_image(data->mlx.ptr, data->pars.ea, &i,
			&j);
	data->mlx.img_no = mlx_xpm_file_to_image(data->mlx.ptr, data->pars.no, &i,
			&j);
	data->mlx.img_so = mlx_xpm_file_to_image(data->mlx.ptr, data->pars.so, &i,
			&j);
	data->mlx.img_we = mlx_xpm_file_to_image(data->mlx.ptr, data->pars.we, &i,
			&j);
	if (!data->mlx.img_ea || !data->mlx.img_no || !data->mlx.img_so
		|| !data->mlx.img_we)
		return (free_img(data), 1);
	return (0);
}

void	view_sens(t_data *data)
{
	data->ray.dir_x = 0;
	data->ray.dir_y = 0;
	data->ray.plane_x = 0;
	data->ray.plane_y = 0;
	if (data->pars.sens == 'S')
	{
		data->ray.dir_y = 1;
		data->ray.plane_x = -0.66;
	}
	else if (data->pars.sens == 'N')
	{
		data->ray.dir_y = -1;
		data->ray.plane_x = 0.66;
	}
	else if (data->pars.sens == 'E')
	{
		data->ray.dir_x = 1;
		data->ray.plane_y = 0.66;
	}
	else if (data->pars.sens == 'W')
	{
		data->ray.dir_x = -1;
		data->ray.plane_y = -0.66;
	}
}

int	create_rgb(int *tab)
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;

	r = (unsigned char)tab[0];
	g = (unsigned char)tab[1];
	b = (unsigned char)tab[2];
	return ((r << 16) | (g << 8) | b);
}

void	init_data(t_data *data)
{
	int	j;
	int	x;

	x = 0;
	data->ray.floor = create_rgb(data->pars.floor);
	data->ray.ciel = create_rgb(data->pars.ceiling);
	view_sens(data);
	while (data->pars.map[x])
	{
		j = 0;
		while (data->pars.map[x][j])
		{
			if (data->pars.map[x][j] == 'N' || data->pars.map[x][j] == 'W'
				|| data->pars.map[x][j] == 'S' || data->pars.map[x][j] == 'E')
			{
				data->ray.pos_x = x + 0.5;
				data->ray.pos_y = j + 0.5;
				break ;
			}
			j++;
		}
		x++;
	}
	data->mlx.win = NULL;
	data->pars.map[(int)data->ray.pos_x][(int)data->ray.pos_y] = '0';
}
