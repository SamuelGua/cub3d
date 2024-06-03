/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:24:49 by scely             #+#    #+#             */
/*   Updated: 2024/05/30 21:34:25 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// char	*maps[] = { "1111111111",
// 					"101000011",
// 					"1100110011",
// 					"11N1000001",
// 					"1010000101",
// 					"1000000101",
// 					"1000000001",
// 					"1010100101",
// 					"1000000001",
// 					"1111111111", "\0"};

int	init_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_get_screen_size(data->mlx.ptr, &j, &i);
	if (SCREEN_W >= j - 1 || SCREEN_H >= i - 1)
		return (printf("Error: Screen too small\n"), 1);
	data->mlx.img_ea = mlx_xpm_file_to_image(data->mlx.ptr, data->pars.EA, &i,
			&j);
	data->mlx.img_no = mlx_xpm_file_to_image(data->mlx.ptr, data->pars.NO, &i,
			&j);
	data->mlx.img_so = mlx_xpm_file_to_image(data->mlx.ptr, data->pars.SO, &i,
			&j);
	data->mlx.img_we = mlx_xpm_file_to_image(data->mlx.ptr, data->pars.WE, &i,
			&j);
	if (!data->mlx.img_ea || !data->mlx.img_no || !data->mlx.img_so
		|| !data->mlx.img_we)
		return (free_img(data), 1);
	return (0);
}

void	view_sens(t_data *data)
{
	//checker si c'est la bonne direction
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
	// CHANGER LES SPIRTES
	//================a supprimer apres parsing========
	// data->pars.EA = ft_strdup("src/sprites/ciel.xpm");
	// data->pars.NO = ft_strdup("src/sprites/god_adam.xpm");
	// data->pars.SO = ft_strdup("src/sprites/man.xpm");
	// data->pars.WE = ft_strdup("src/sprites/picasso.xpm");
	// if (!data->pars.WE ||!data->pars.SO
	// 	|| !data->pars.EA || !data->pars.NO)
	// 	exit(1);
	// data->pars.maps = malloc(sizeof(char *) * 12);
	// if (!data->pars.maps)
	// 		exit(1);
	// for (int i = 0; maps[i]; i++)
	// {
	// 	data->pars.maps[i] = ft_strdup(maps[i]);
	// 	if (!data->pars.maps[i])
	// 		exit(1);
	// }
	// data->pars.maps[11] = NULL;
	// data->pars.floor[0] = 101;
	// data->pars.floor[1] = 67;
	// data->pars.floor[2] = 33;
	// data->pars.ciel[0] = 173;
	// data->pars.ciel[1] = 216;
	// data->pars.ciel[2] = 230;
	//====================================

	data->ray.floor = create_rgb(data->pars.floor);
	data->ray.ciel = create_rgb(data->pars.ceiling);
	data->pars.sens = data->pars.sens;
	view_sens(data);

	//===============verifier si ca fonctionne sur les extreme=======
	////[1;1] || {111,101,111};
	int x = 0;
	int j = 0;
	while(data->pars.map[x])
	{
		j = 0;
		while (data->pars.map[x][j])
		{
			if (data->pars.map[x][j] == 'N' || data->pars.map[x][j] == 'W'  
				|| data->pars.map[x][j] == 'S'  || data->pars.map[x][j] == 'E')
				{
					data->ray.pos_x = x + 0.5;
					data->ray.pos_y = j + 0.5;
				}
			j++;
		}
		x++;
	}
	//data->ray.pos_x = x + 0.5;
	//data->ray.pos_y = j + 0.5;
	//===============================================================
	data->pars.map[(int)data->ray.pos_x][(int)data->ray.pos_y] = '0';
}
