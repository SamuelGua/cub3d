/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:36:51 by cfelix            #+#    #+#             */
/*   Updated: 2022/12/14 15:37:02 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlcpy2(char **dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		(*dst)[i] = src[i];
		i++;
	}
	(*dst)[i] = '\0';
}

int	found_new_line(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	char_until_end(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

void	clean_stash(char **stash)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	temp = malloc(sizeof(char) * (ft_strlen(*stash) - i) + 1);
	if (temp == NULL)
		return ;
	while ((*stash)[i])
		temp[j++] = (*stash)[i++];
	temp[j] = '\0';
	free(*stash);
	*stash = malloc(sizeof(char) * (ft_strlen(temp)+ 1));
	if (*stash == NULL)
		return ;
	ft_strlcpy2(stash, temp);
	free(temp);
}
