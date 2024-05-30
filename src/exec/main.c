/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:17:45 by scely             #+#    #+#             */
/*   Updated: 2024/05/30 09:08:40 by scely            ###   ########.fr       */
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
	"1010101001",
	"1000001001",
	"10N0000001",
	"1010000101",
	"1000000101",
	"1000000001",
	"1010100101",
	"1000000001",
	"1111111111",
	"\0"
};

void view_sens(t_data *data)
{
	data->ray.dir_x = 0;
	data->ray.dir_y = 0;
	data->ray.plane_x = 0;
	data->ray.plane_y = 0;
	if (data->pars.sens == NORTH)
	{
		data->ray.dir_y = 1;
		data->ray.plane_x = -0.66;
	}
	else if (data->pars.sens == SOUTH)
	{
		data->ray.dir_y = -1;
		data->ray.plane_x = 0.66;
	} 
	else if (data->pars.sens == EAST)
	{
		data->ray.dir_x = 1;
		data->ray.plane_y = 0.66;
	}
	else if (data->pars.sens == WEST)
	{
		data->ray.dir_x = -1;
		data->ray.plane_y = -0.66;
	}
}

int	create_rgb(int *tab)
{
	unsigned char b;
	unsigned char g;
	unsigned char r;

	r = (unsigned char)tab[0];
	g = (unsigned char)tab[1];
	b = (unsigned char)tab[2];
	return ((r << 16) | (g << 8) | b);
}
void init_data(t_data *data)
{
	// CHANGER LES SPIRTES
	data->pars.EA = ft_strdup("src/sprites/ciel.xpm");
	data->pars.NO = ft_strdup("src/sprites/god_adam.xpm");
	data->pars.SO = ft_strdup("src/sprites/man.xpm");
	data->pars.WE = ft_strdup("src/sprites/picasso.xpm");

	data->pars.maps = malloc(sizeof(char *) * 12);
	for (int i = 0; maps[i]; i++)
		data->pars.maps[i] = ft_strdup(maps[i]);
	data->pars.maps[11] = NULL;
	
	data->pars.floor[0] = 101; data->pars.floor[1] = 67; data->pars.floor[2] = 33;
	data->pars.ciel[0] = 173; data->pars.ciel[1] = 216; data->pars.ciel[2] = 230;
	data->ray.floor = create_rgb(data->pars.floor);
	data->ray.ciel = create_rgb(data->pars.ciel);

	data->pars.sens = WEST;
	view_sens(data);

// pos a changer si probleme
	data->ray.pos_x = 3.5;
	data->ray.pos_y = 2.5;

// PEUT ETRE A CHANGER
	data->pars.maps[(int)data->ray.pos_x][(int)data->ray.pos_y] = '0';

}

int	close_window(t_data *data)
{
	//free all
	//free pars
	free_img(data);
	free_mlx(data);
	exit(1);
}

int	key_capt(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	made_mouv(data, keycode);
	castray(data);
	return (0);
}


// la carte est a l'envers
int	main(int ac, char *av[])
{
	t_data data;

	if (ac != 2 || !av)
		return (printf("GIVE A PARAMETER\n"), 1);
	init_data(&data);
	data.mlx.ptr = mlx_init();
	if (!data.mlx.ptr)
		return (/*free parsing*/ printf("Error: MLX_INIT\n"), 1);
	if (init_img(&data))
		return (/*free parsing*/free_mlx(&data), printf("Error IMG_INIT\n"), 1);
	data.mlx.win = mlx_new_window(data.mlx.ptr, SCREEN_W, SCREEN_H, "CUD3D");
	if (!data.mlx.win)
	{
		free_img(&data);
		free_mlx(&data);
		return (/*free parsing*/ printf("Error: WIN_INIT\n"), 1);
	}

	castray(&data);
	mlx_hook(data.mlx.win, 2, 1L << 0, key_capt, &data);
	mlx_hook(data.mlx.win, 17, 1L << 17, close_window, &data);
	// mlx_loop_hook(data.mlx.ptr, castray, &data);
	mlx_loop(data.mlx.ptr);

}
