/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:50:59 by cfelix            #+#    #+#             */
/*   Updated: 2024/06/03 19:28:51 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_rgb_line(char *line)
{
	int	i;
	int	flag;

	flag = 0;
	i = 1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '\n')
	{
		while (ft_isdigit(line[i]) || line[i] == ',')
		{
			if (line[i] == ',' && ft_isdigit(line[i-1])
				&& ft_isdigit(line[i+1]))
				flag++; 
			i++;
		}
	}
	while (line[i] == ' ' || line[i] == '\t')
			i++;
	if (line[i] != '\n' || flag != 2)
		return (0);
	return (1);
}

void	free_all(t_parsing *data)
{
	int	i;

	i = 0;
	free(data->no);
	free(data->so);
	free(data->we);
	free(data->ea);
	if(data->map == NULL)
		return ;
	while (data->map[i] != NULL)
		free(data->map[i++]);
	free(data->map);
}

int	is_map(int i, int j, t_parsing *data, char **map)
{
	if ((map[i - 1][j] != '1' && map[i - 1][j] != '0' && map[i
			- 1][j] != data->sens))
		return (0);
	if ((map[i + 1][j] != '1' && map[i + 1][j] != '0' && map[i
			+ 1][j] != data->sens))
		return (0);
	if ((map[i][j - 1] != '1' && map[i][j - 1] != '0' && map[i][j
			- 1] != data->sens))
		return (0);
	if ((map[i][j + 1] != '1' && map[i][j + 1] != '0' && map[i][j
			+ 1] != data->sens))
		return (0);
	return (1);
}

int	is_map2(int i, int j, t_parsing *data, char **map)
{
	if ((map[i - 1][j - 1] != '1' && map[i - 1][j - 1] != '0' && map[i - 1][j
			- 1] != data->sens))
		return (0);
	if ((map[i - 1][j + 1] != '1' && map[i - 1][j + 1] != '0' && map[i - 1][j
			+ 1] != data->sens))
		return (0);
	if ((map[i + 1][j - 1] != '1' && map[i + 1][j - 1] != '0' && map[i + 1][j
			- 1] != data->sens))
		return (0);
	if ((map[i + 1][j + 1] != '1' && map[i + 1][j + 1] != '0' && map[i + 1][j
			+ 1] != data->sens))
		return (0);
	return (1);
}

char	*skip_to_value(char *line)
{
	int	i;

	i = 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (&line[i]);
}
