/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:21:42 by scely             #+#    #+#             */
/*   Updated: 2024/06/03 19:30:03 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_pars(t_data *data)
{
	ft_free(data->pars.map);
	free(data->pars.no);
	free(data->pars.so);
	free(data->pars.ea);
	free(data->pars.we);
}

void	free_img(t_data *data)
{
	if (data->mlx.img_no)
		mlx_destroy_image(data->mlx.ptr, data->mlx.img_no);
	if (data->mlx.img_ea)
		mlx_destroy_image(data->mlx.ptr, data->mlx.img_ea);
	if (data->mlx.img_so)
		mlx_destroy_image(data->mlx.ptr, data->mlx.img_so);
	if (data->mlx.img_we)
		mlx_destroy_image(data->mlx.ptr, data->mlx.img_we);
}

void	free_mlx(t_data *data)
{
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	mlx_destroy_display(data->mlx.ptr);
	free(data->mlx.ptr);
}

int	close_window(t_data *data)
{
	free_pars(data);
	free_img(data);
	free_mlx(data);
	exit(0);
}
