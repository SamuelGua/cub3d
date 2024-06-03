/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:50:40 by cfelix            #+#    #+#             */
/*   Updated: 2024/06/03 17:50:41 by cfelix           ###   ########.fr       */
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
		return (0);
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
		if (ft_strncmp(*line, "NO ", 3) == 0)
			data->NO = ft_strdup2(skip_to_value(*line));
		else if (ft_strncmp(*line, "SO ", 3) == 0)
			data->SO = ft_strdup2(skip_to_value(*line));
		else if (ft_strncmp(*line, "WE ", 3) == 0)
			data->WE = ft_strdup2(skip_to_value(*line));
		else if (ft_strncmp(*line, "EA ", 3) == 0)
			data->EA = ft_strdup2(skip_to_value(*line));
		else if (ft_strncmp(*line, "F ", 2) == 0 || ft_strncmp(*line, "C ",
				2) == 0)
		{
			if (valid_rgb_line(*line) == 0)
			{
				data->floor[0] = -1;
				data->floor[0] = -1;
			}
			else
				get_rgb(data, *line);
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
	int	i;

	i = 0;
	data->stash = NULL;
	data->map_height = 0;
	while (*line != NULL)
	{
		if (is_only_digits_or_whitespace(*line))
		{
			while (*line && is_only_digits_or_whitespace(*line))
			{
				data->map_height++;
				(stock_line(data, *line), free(*line));
				*line = get_next_line(fd);
			}
			break ;
		}
		free(*line);
		*line = get_next_line(fd);
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
