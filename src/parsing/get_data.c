/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:50:40 by cfelix            #+#    #+#             */
/*   Updated: 2024/06/03 19:35:11 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_data(t_parsing *data)
{
	char	*line;
	int		fd;

	fd = open(data->name, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		return (0);
	}
	get_texture(data, &line, fd);
	get_map_height(data, &line, fd);
	get_map(data);
	get_sens(data);
	return (1);
}

void	get_texture(t_parsing *data, char **line, int fd)
{
	while (*line && !is_only_digits_or_whitespace(*line))
	{
		if (ft_strncmp(*line, "NO", 2) == 0 && data->no == NULL)
			data->no = ft_strdup2(skip_to_value(*line));
		else if (ft_strncmp(*line, "SO", 2) == 0 && data->so == NULL)
			data->so = ft_strdup2(skip_to_value(*line));
		else if (ft_strncmp(*line, "WE", 2) == 0 && data->we == NULL)
			data->we = ft_strdup2(skip_to_value(*line));
		else if (ft_strncmp(*line, "EA", 2) == 0 && data->ea == NULL)
			data->ea = ft_strdup2(skip_to_value(*line));
		else if (((ft_strncmp(*line, "F", 1) == 0 && data->floor[0] == -1) || (ft_strncmp(*line, "C",
				1) == 0 && data->ceiling[0] == -1)) && valid_rgb_line(*line))
				get_rgb(data, *line);
		else if (!ft_is_whitespaces(*line))
		{
			if (data->no != NULL)
			{
				free (data->no);
				data->no = NULL;
			}
			break ;
		}
		free(*line);
		*line = get_next_line(fd);
	}
}

void	get_rgb(t_parsing *data, char *line)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (ft_strncmp(line, "F", 1) == 0)
	{
		while (x < 3)
		{
			i += goto_next_value(&line[i]);
			data->floor[x++] = ft_atoi(&line[i]);
		}
	}
	if (ft_strncmp(line, "C", 1) == 0)
	{
		while (x < 3)
		{
			i += goto_next_value(&line[i]);
			data->ceiling[x++] = ft_atoi(&line[i]);
		}
	}
}

void	get_map_height(t_parsing *data, char **line, int fd)
{

	if (*line != NULL && is_only_digits_or_whitespace(*line))
	{
		while (*line)
		{
			data->map_height++;
			(stock_line(data, *line), free(*line));
			*line = get_next_line(fd);
		}
	}
	while (*line)
		(free(*line), *line = get_next_line(fd));
	close(fd);
}

int	get_map(t_parsing *data)
{
	data->map = ft_split(data->stash, '\n');
	if (data->map == NULL)
		return (0);
	free(data->stash);
	return (1);
}
