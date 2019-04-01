#include "fdf.h"

void	display_hud(t_map *map)
{
	mlx_string_put(map->mlx_ptr,
		map->win_ptr, 10, 10, 0xFFFFFF, "FDF");
	mlx_string_put(map->mlx_ptr,
		map->win_ptr, 10, 40, 0xFFFFFF, "press [i] to check inputs");
	mlx_string_put(map->mlx_ptr,
		map->win_ptr, 10, 70, 0xFFFFFF, "colors  :");
	if (map->params->colors == 0)
		mlx_string_put(map->mlx_ptr, map->win_ptr, 110, 70, 0xFFFFFF, "off");
	else
		mlx_string_put(map->mlx_ptr, map->win_ptr, 110, 70, 0xFFFFFF, "on");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 90, 0xFFFFFF, "view    :");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 110, 90, 0xFFFFFF, "isometric");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 110, 0xFFFFFF, "mode    :");
	if (map->params->split == 0)
		mlx_string_put(map->mlx_ptr, map->win_ptr,
		110, 110, 0xFFFFFF, "standard");
	else
		mlx_string_put(map->mlx_ptr, map->win_ptr, 110, 110, 0xFFFFFF, "split");

	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 130, 0xFFFFFF, "zoom    :");
	ft_nbr_string_put(110, 130, map->size_bloc, map);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 160, 0xFFFFFF, "delta z : ");
	ft_nbr_string_put(110, 160, map->z_height, map);
}
