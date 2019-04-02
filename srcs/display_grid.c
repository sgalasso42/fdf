#include "fdf.h"

t_pos	ft_calc_coord(t_map *map, int i, int j)
{
	t_pos	pos;

	pos.x = (j - i) * (map->size_bloc / 2);
	pos.y = (j + i) * (map->size_bloc / 4);
	pos.x += map->map_w / 2 + map->params.tx;
	pos.y += map->map_h / 2 + map->params.ty;
	pos.y -= ((map->grid[i][j] * map->z_height) * (map->size_bloc / 4));
	return (pos);
}

void	display_grid(t_map *map)
{
	int		i;
	int		j;
	t_vec	vec;

	i = 0;
	while (i < map->nb_y)
	{
		j = 0;
		while (j < map->nb_x)
		{
			vec.a = ft_calc_coord(map, i, j);
			if (j < map->nb_x - 1)
			{
				vec.b = ft_calc_coord(map, i, j + 1);
				ft_draw_line(&vec.a, &vec.b, map, 0XFFFFFF);
			}
			if (i < map->nb_y - 1)
			{
				vec.c = ft_calc_coord(map, i + 1, j);
				ft_draw_line(&vec.a, &vec.c, map, 0XFFFFFF);
			}
			j++;
		}
		i++;
	}
}
