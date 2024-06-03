
#include "cub3d.h"

static int	check_top_or_bottom(char **map_tab, int i, int j)
{
	while (map_tab[i][j] == ' ' || map_tab[i][j] == '\t')
		j++;
	while (map_tab[i][j])
	{
		if (map_tab[i][j] != '1' &&
            map_tab[i][j] != ' ' && map_tab[i][j] != '\t')
			return (0);
		j++;
	}
	return (1);
}

int	check_map_wall(t_parsing *data, char **map)
{
	int	i;
	int	j;

	if (check_top_or_bottom(map, 0, 0) == 0)
		return (0);
	i = 1;
	while (i < (data->map_height - 1))
	{
        j = 0;
        while(map[i][j] == ' ' || map[i][j] == '\t')
            j++;
        if (map[i][j] != '1')
            return (0);
		j = ft_strlen(map[i]) - 1;
		if (map[i][j] != '1')
			return (0);
		i++;
	}
	if (check_top_or_bottom(map, i, 0) == 0)
		return (0);
	return (1);
}

int check_all_floor(t_parsing *data, char **map)
{
    if (check_close_floor(data, map) == 0)
        return (0);
    if (check_diag_floor(data, map) == 0)
        return (0);
    return (1);
}

int check_close_floor(t_parsing *data, char **map)
{
    int i;
    int j;

    i = 0;
    while (i < (data->map_height - 1))
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == '0')
            {
                if ((map[i - 1][j] != '1' && map[i - 1][j] != '0' && map[i - 1][j] != data->sens))  // en haut
                    return(0);
                if ((map[i + 1][j] != '1' && map[i + 1][j] != '0' && map[i + 1][j] != data->sens))  // en bas
                    return(0);
                if ((map[i][j - 1] != '1' && map[i][j - 1] != '0' && map[i][j - 1] != data->sens)) // à gauche
                    return (0);
                if ((map[i][j + 1] != '1' && map[i][j + 1] != '0' && map[i][j + 1] != data->sens)) // à droite
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

int check_diag_floor(t_parsing *data, char **map)
{
    int i;
    int j;

    i = 0;
    while (i < (data->map_height - 1))
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == '0')
            {
                if ((map[i - 1][j - 1] != '1' && map[i - 1][j - 1] != '0' && map[i - 1][j - 1] != data->sens))  // en haut a gauche
                    return(0);
                if ((map[i - 1][j + 1] != '1' && map[i - 1][j + 1] != '0' && map[i - 1][j + 1] != data->sens))  // en haut a droite
                    return(0);
                if ((map[i + 1][j - 1] != '1' && map[i + 1][j - 1] != '0' && map[i + 1][j - 1] != data->sens)) // en bas à gauche
                    return (0);
                if ((map[i + 1][j + 1] != '1' && map[i + 1][j + 1] != '0' && map[i + 1][j + 1] != data->sens)) // en bas à droite
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}