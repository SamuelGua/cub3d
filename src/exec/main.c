/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:17:45 by scely             #+#    #+#             */
/*   Updated: 2024/06/03 18:39:51 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_capt(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	made_mouv(data, keycode);
	if (castray(data))
	{
		write(1, "Error: FAIL TO CAST RAY\n", 25);
		free_pars(data);
		free_img(data);
		free_mlx(data);
		exit(1);
	}
	return (0);
}

int	mlx_routine(t_data *data)
{
	init_data(data);
	data->mlx.ptr = mlx_init();
	if (!data->mlx.ptr)
		return (free_pars(data), write(1, "Error: FAIL TO INIT MLX\n", 25), 1);
	if (init_img(data))
		return (free_pars(data), free_mlx(data),
			write(1, "Error: FAIL TO INIT IMG\n", 25), 1);
	data->mlx.win = mlx_new_window(data->mlx.ptr, SCREEN_W, SCREEN_H, "CUD3D");
	if (!data->mlx.win)
	{
		free_img(data);
		free_mlx(data);
		return (free_pars(data), write(1, "Error: FAIL TO CREAT WINDOW\n", 29), 1);
	}
	if (castray(data))
	{
		write(1, "Error: FAIL TO CAST RAY\n", 25);
		(free_pars(data), free_img(data), free_mlx(data));
		exit(1);
	}
	mlx_hook(data->mlx.win, 2, 1L << 0, key_capt, data);
	mlx_hook(data->mlx.win, 17, 1L << 17, close_window, data);
	mlx_loop(data->mlx.ptr);
	return (0);
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac != 2 || !av)
		return (write(1, "GIVE A PARAMETER\n", 18), 1);
	init_null(&data.pars);
	data.pars.name = av[1];
	if (checkformat(data.pars.name, ".cub") == 0)
		return (0);
	if (get_check_all(&data.pars) == 0)
	{
		free_all(&data.pars);
		return (0);
	}
	mlx_routine(&data);
	return (0);
}
