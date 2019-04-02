#include "fdf.h"

void    ft_calc_size_map(t_map *map)
{
	map->map_w = map->nb_x * map->size_bloc;
	map->map_h = map->nb_y * ((map->size_bloc + 20) / 2);
	(map->map_w > 1200) ? map->map_w = 1200 : 0;
	(map->map_w < 800) ? map->map_w = 800 : 0;
	(map->map_h > 800) ? map->map_h = 800 : 0;
	(map->map_h < 500) ? map->map_h = 500 : 0;
}

void	ft_init_fdf(t_map *map)
{
	map->size_bloc = 40;
	map->z_height = 1;
	map->mlx_ptr = mlx_init();
	ft_calc_size_map(map);
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->map_w, map->map_h, "fdf");
}
