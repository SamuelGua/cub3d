#include "cub3d.h"

void get_sens(t_parsing *data)
{
	int i;
	int j;
	
	i = 0;
    while (data->map[i] != NULL)
    {
		j = 0;
        while (data->map[i][j] != '\0')
        {
            if (data->map[i][j] == 'N' || data->map[i][j] == 'S' ||
				data->map[i][j] == 'E' || data->map[i][j] == 'W')
            {
                data->sens = data->map[i][j];
                return;
            }
            j++;
        }
		i++;
    }
}