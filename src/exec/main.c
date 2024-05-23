/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:17:45 by scely             #+#    #+#             */
/*   Updated: 2024/05/23 23:35:57 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//struture temporaire
#define NORD 1
#define SUD 2
#define EST 3
#define WEST 4

char *maps[] = {
	"1111111111",
	"1N00000001",
	"1010101001",
	"1000000101",
	"1111011111",
	"1010000001",
	"1001000001",
	"1000100001",
	"1000001001",
	"1111111111",
};

typedef struct data
{
    char *NO;
    char *SO;
    char *WE;
    char *EA;

    int floor[3];
    int ciel[3];

    char **maps;
    
    int posx;
    int posy;
    char sens;
} data;

void init_data(data *data)
{
	// CHANGER LES SPIRTES
	data->EA = ft_strdup("src/sprites/aloy.webp");
	data->NO = ft_strdup("src/sprites/bayek.webp");
	data->SO = ft_strdup("src/sprites/ichigo.webp");
	data->WE = ft_strdup("src/sprites/sharigan.webp");

	data->floor[0] = 0; 
	data->floor[1] = 0; 
	data->floor[2] = 0;

	data->ciel[0] = 255; 
	data->ciel[1] = 255; 
	data->ciel[2] = 255;

	data->maps = maps;

	data->posx = 1;
	data->posy = 1;
	data->sens = NORD;

}

int	main(int ac, char *av[])
{
	(void)av;
	data data;
	init_data(&data);
	printf("%s\n", data.maps[0]);
	printf("%d\n", data.posx);
	if (ac != 2)
		return (ft_putstr_fd("wrongs arguments numbers\n",2), 1);
}