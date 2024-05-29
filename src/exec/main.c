/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:17:45 by scely             #+#    #+#             */
/*   Updated: 2024/05/29 12:23:50 by scely            ###   ########.fr       */
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
	"1010000001",
	"1000100001",
	"10N0000001",
	"1000000101",
	"1000000001",
	"1000000001",
	"1010100101",
	"1000000001",
	"1111111111",
	"\0"
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

	data->pars.maps = malloc(sizeof(char *) * 11);
	for (int i = 0; maps[i]; i++)
		data->pars.maps[i] = ft_strdup(maps[i]);
	data->pars.maps[11] = NULL;
	

	data->ray.dir_x = 1;
	data->ray.dir_y = 0;

	// pos a changer si probleme
	data->ray.pos_x = 2.5;
	data->ray.pos_y = 2.5;

	data->ray.plane_x = 0;
	data->ray.plane_y = 0.66;
// PEUT ETRE A CHANGER
	if (data->pars.maps[(int)data->ray.pos_x][(int)data->ray.pos_y])
		data->pars.maps[(int)data->ray.pos_x][(int)data->ray.pos_y] = '0';

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
	made_mouv(data, keycode);
	for (int i = 0; data->pars.maps[i]; i++)
		printf("=> %s\n", data->pars.maps[i]);
	// mlx_clear_window(data->mlx.ptr, data->mlx.win);
	castray(data);
	return (0);
}


// la carte est a l'envers
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

	castray(&data);

	mlx_hook(data.mlx.win, 2, 1L << 0, key_capt, &data);

	mlx_hook(data.mlx.win, 17, 1L << 17, close_window, &data);
	mlx_loop(data.mlx.ptr);

}
