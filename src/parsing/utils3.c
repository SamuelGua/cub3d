/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:50:59 by cfelix            #+#    #+#             */
/*   Updated: 2024/06/03 19:28:51 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_null(t_parsing *data)
{
    data->name = NULL;
    data->map = NULL;
    data->no = NULL;
    data->so = NULL;
    data->we = NULL;
    data->ea = NULL;
    data->sens = 0;
    data->map_height = 0;
    data->floor[0] = -1;
    data->floor[1] = -1;
    data->floor[2] = -1;
    data->ceiling[0] = -1;
    data->ceiling[1] = -1;
    data->ceiling[2] = -1;
    data->stash = NULL;
}