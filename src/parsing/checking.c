/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:50:10 by cfelix            #+#    #+#             */
/*   Updated: 2024/06/03 19:29:39 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_check_all(t_parsing *data)
{
	if (get_data(data) == 0)
		return (0);
	if (check_data(data) == 0)
		return (0);
	return (1);
}

int	checkformat(char *name, char *format)
{
	size_t	i;
	size_t	size;
	int		j;

	size = ft_strlen(name);
	i = size - 1;
	j = 0;
	while (name[i] != format[0] && i > 0)
		i--;
	if (i == 0)
		return (0);
	while (name[i + j] == format[j] && name[i + j] != '\0')
		j++;
	if (name[i + j] == '\0')
	{
		if (size - ft_strlen(format) == i)
			return (1);
	}
	write(1, "Error\nThe chosen map isn't in the .cub format\n", 47);
	return (0);
}

int	check_data(t_parsing *data)
{
	if (check_data_texture(data) == 0)
		return (0);
	if (data->map == NULL)
	{
		write(1, "Error\nMap missing\n", 19);
		return (0);
	}
	if (check_map_elem(data->map) == 0)
	{
		write(1, "Error\nMap invalid\n", 19);
		return (0);
	}
	if (check_map_wall(data, data->map) == 0)
	{
		write(1, "Error\nMap invalid\n", 19);
		return (0);
	}
	if (check_all_floor(data, data->map) == 0)
	{
		write(1, "Error\nMap invalid\n", 19);
		return (0);
	}
	return (1);
}

int	check_data_texture(t_parsing *data)
{
	if (data->no == NULL || data->so == NULL || data->we == NULL
		|| data->ea == NULL)
	{
		write(1, "Error\nTexture path missing\n", 28);
		return (0);
	}
	if (data->floor[0] < 0 || data->floor[0] > 255 || data->floor[1] < 0
		|| data->floor[1] > 255 || data->floor[2] < 0 || data->floor[2] > 255)
	{
		write(1, "Error\nFloor color missing or invalid\n", 38);
		return (0);
	}
	if (data->ceiling[0] < 0 || data->ceiling[0] > 255 || data->ceiling[1] < 0
		|| data->ceiling[1] > 255 || data->ceiling[2] < 0
		|| data->ceiling[2] > 255)
	{
		write(1, "Error\nCeiling color missing or invalid\n", 40);
		return (0);
	}
	return (1);
}

int	check_map_elem(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				count++;
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' '
				&& map[i][j] != '\t')
				return (0);
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}
