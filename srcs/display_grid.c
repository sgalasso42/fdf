#include "fdf.h"

int		ft_select_color(int val)
{
	int		res;
	int		r;
	int		g;
	int		b;

	val++;
	res = 0;
	r = R_MIN + val * R_DELTA;
	g = G_MIN + val * G_DELTA;
	b = B_MIN + val * B_DELTA;
	res += r << 8;
	res += g << 4;
	res += b;
	return (res);
}

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

void	ft_calc_color_ab(t_vec *vec, t_map *map, int i, int j)
{
	int		higher;

	higher = 0;
	vec->a = ft_calc_coord(map, i, j);
	vec->b = ft_calc_coord(map, i, j + 1);
	vec->color_ab = 0xFFFFFF;
	if (map->params.colors == 1)
	{
		higher = (map->grid[i][j] < map->grid[i][j + 1])
		? map->grid[i][j + 1] : map->grid[i][j];
		(higher > 10) ? higher = 10 : 0;
		vec->color_ab = (higher > 0) ? ft_select_color(higher) : 0x74D2;
	}
}

void	ft_calc_color_ac(t_vec *vec, t_map *map, int i, int j)
{
	int		higher;

	higher = 0;
	vec->a = ft_calc_coord(map, i, j);
	vec->c = ft_calc_coord(map, i + 1, j);
	vec->color_ac = 0xFFFFFF;
	if (map->params.colors == 1)
	{
		higher = (map->grid[i][j] < map->grid[i + 1][j])
		? map->grid[i + 1][j] : map->grid[i][j];
		(higher > 10) ? higher = 10 : 0;
		vec->color_ac = (higher > 0) ? ft_select_color(higher) : 0x74D2;
	}
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
			if (j < map->nb_x - 1)
			{
				ft_calc_color_ab(&vec, map, i, j);
				ft_draw_line(&vec.a, &vec.b, map, vec.color_ab);
			}
			if (i < map->nb_y - 1)
			{
				ft_calc_color_ac(&vec, map, i, j);
				ft_draw_line(&vec.a, &vec.c, map, vec.color_ac);
			}
			j++;
		}
		i++;
	}
}
