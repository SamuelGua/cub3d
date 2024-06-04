/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:51:25 by cfelix            #+#    #+#             */
/*   Updated: 2024/06/03 19:36:11 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	goto_next_value(char *line)
{
	int	i;

	i = 0;
	if (!ft_isdigit(line[i]))
	{
		while (!ft_isdigit(line[i]))
			i++;
	}
	else if (ft_isdigit(line[i]))
	{
		while (ft_isdigit(line[i]))
			i++;
		i++;
	}
	return (i);
}

char	*ft_strdup2(char *line)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup(&line[0]);
	if (!str)
		return (NULL);
	while (str[i] != '\n')
		i++;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
		str[i--] = '\0';
	return (str);
}

int	extend_stash2(t_parsing *data, char *buf)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(char) * (ft_strlen(data->stash) + 1));
	if (temp == NULL)
		return (0);
	while ((data->stash)[i])
	{
		temp[i] = (data->stash)[i];
		i++;
	}
	temp[i] = '\0';
	free(data->stash);
	data->stash = malloc(sizeof(char) * (i + ft_strlen(buf) + 1));
	if (data->stash == NULL)
		return (0);
	i = 0;
	while (temp[i])
	{
		(data->stash)[i] = temp[i];
		i++;
	}
	free(temp);
	return (i);
}

void	stock_line(t_parsing *data, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (data->stash == NULL)
	{
		data->stash = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (data->stash == NULL)
			return ;
	}
	else
		j = extend_stash2(data, line);
	while (line[i])
		data->stash[j++] = line[i++];
	data->stash[j] = '\0';
}

int	is_only_digits_or_whitespace(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '\t'
			&& str[i] != '\n' && str[i] != 'N' && str[i] != 'E' && str[i] != 'W'
			&& str[i] != 'S')
			return (0);
		else if (ft_isdigit(str[i]) && flag == 0)
			flag = 1;
		i++;
	}
	if (flag == 0)
		return (0);
	return (1);
}
