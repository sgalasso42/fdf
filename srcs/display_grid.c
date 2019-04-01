#include "../includes/fdf.h"

void	display_grid(t_map *map)
{
	int		i;
	int		j;
	t_vec	vec;

	i = 0;
	map->size_diag->x = (map->nb_x * map->size_bloc) / 2 - map->nb_x;
	map->size_diag->y = (map->nb_y * map->size_bloc) / 4 - map->nb_y;
	while (i < map->nb_y)
	{
		j = 0;
		while (j < map->nb_x)
		{
			ft_calc_coord(&vec, map, i, j);
			j++;
		}
		i++;
	}
}
