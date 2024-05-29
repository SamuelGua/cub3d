/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:24:49 by scely             #+#    #+#             */
/*   Updated: 2024/05/29 22:47:01 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
