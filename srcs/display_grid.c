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

void	ft_calc_coord_a(t_vec *vec, t_map *map, int i, int j)
{
	vec->a.x = (j - i) * (map->size_bloc / 2);
	vec->a.y = (j + i) * (map->size_bloc / 4);
	vec->a.x += map->map_w / 2 + map->params.tx;
	vec->a.y += map->map_h / 2 + map->params.ty;
	vec->a.y -= ((map->grid[i][j] * map->z_height) * (map->size_bloc / 4));
}

void	ft_calc_coord_b(t_vec *vec, t_map *map, int i, int j)
{
	vec->b.x = ((j + 1) - i) * (map->size_bloc / 2);
	vec->b.y = ((j + 1) + i) * (map->size_bloc / 4);
	vec->b.x += map->map_w / 2 + map->params.tx;
	vec->b.y += map->map_h / 2 + map->params.ty;
	vec->b.y -= ((map->grid[i][j + 1] * map->z_height) * (map->size_bloc / 4));
}

void	ft_calc_coord_c(t_vec *vec, t_map *map, int i, int j)
{
	vec->c.x = (j - (i + 1)) * (map->size_bloc / 2);
	vec->c.y = (j + (i + 1)) * (map->size_bloc / 4);
	vec->c.x += map->map_w / 2 + map->params.tx;
	vec->c.y += map->map_h / 2 + map->params.ty;
	vec->c.y -= ((map->grid[i + 1][j] * map->z_height) * (map->size_bloc / 4));
}

void	ft_calc_coord_d(t_vec *vec, t_map *map, int i, int j)
{
	vec->d.x = ((j + 1) - (i + 1)) * (map->size_bloc / 2);
	vec->d.y = ((j + 1) + (i + 1)) * (map->size_bloc / 4);
	vec->d.x += map->map_w / 2 + map->params.tx;
	vec->d.y += map->map_h / 2 + map->params.ty;
	vec->d.y -= ((map->grid[i + 1][j + 1] * map->z_height) * (map->size_bloc / 4));
}

void	ft_calc_color_ab(t_vec *vec, t_map *map, int i, int j)
{
	int		higher;

	ft_calc_coord_a(vec, map, i, j);
	ft_calc_coord_b(vec, map, i, j);

	higher = 0;
	vec->color_ab = 0xFFFFFF;
	if (map->params.colors == 1)
	{
		higher = (map->grid[i][j] < map->grid[i][j + 1])
		? map->grid[i][j + 1] : map->grid[i][j];
		if (higher > 10)
			higher = 10;
		if (higher > 0)
			vec->color_ab = ft_select_color(higher);
		else
			vec->color_ab = 0x74D2;
	}
}

void	ft_calc_color_ac(t_vec *vec, t_map *map, int i, int j)
{
	int		higher;

	ft_calc_coord_a(vec, map, i, j);
	ft_calc_coord_c(vec, map, i, j);

	higher = 0;
	vec->color_ac = 0xFFFFFF;
	if (map->params.colors == 1)
	{
		higher = (map->grid[i][j] < map->grid[i + 1][j])
		? map->grid[i + 1][j] : map->grid[i][j];
		if (higher > 10)
			higher = 10;
		if (higher > 0)
			vec->color_ac = ft_select_color(higher);
		else
			vec->color_ac = 0x74D2;
	}
}

void	ft_calc_color_cb(t_vec *vec, t_map *map, int i, int j)
{
	int		higher;

	higher = 0;
	vec->color_cb = 0xFFFFFF;
	if (map->params.colors == 1)
	{
		higher = (map->grid[i + 1][j] < map->grid[i][j + 1])
		? map->grid[i][j + 1] : map->grid[i + 1][j];
		if (higher > 10)
			higher = 10;
		if (higher > 0)
			vec->color_cb = ft_select_color(higher);
		else
			vec->color_cb = 0x74D2;
	}
}

void	ft_calc_color_ad(t_vec *vec, t_map *map, int i, int j)
{
	int		higher;

	higher = 0;
	vec->color_ad = 0xFFFFFF;
	if (map->params.colors == 1)
	{
		higher = (map->grid[i][j] < map->grid[i + 1][j + 1])
		? map->grid[i + 1][j + 1] : map->grid[i][j];
		if (higher > 10)
			higher = 10;
		if (higher > 0)
			vec->color_ad = ft_select_color(higher);
		else
			vec->color_ad = 0x74D2;
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
