#include "cub3d.h"

int valid_rgb_line(char *line)
{
    int i;

    i = 1;
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    if (line[i] != '\n')
    {
        while(ft_isdigit(line[i]) || line[i] == ',')
            i++;
        while (line[i] == ' ' || line[i] == '\t')
            i++;
    }
    if (line[i] != '\n')
        return (0);
    return (1);
}
void free_all(t_parsing *data)
{
	int i;

	i = 0;
	free(data->NO);
    free(data->SO);
    free(data->WE);
    free(data->EA);
	while (data->map[i] != NULL)
   		free(data->map[i++]);
    free(data->map);
}