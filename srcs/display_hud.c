#include "fdf.h"

void	display_hud(t_map *map)
{
	mlx_string_put(map->mlx_ptr,
		map->win_ptr, 10, 10, 0xFFFFFF, "FDF");
	mlx_string_put(map->mlx_ptr,
		map->win_ptr, 10, 40, 0xFFFFFF, "press [i] to check inputs");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 70, 0xFFFFFF, "colors  :");
	ft_nbr_string_put(110, 70, map->params.colors, map);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 90, 0xFFFFFF, "view    :");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 110, 90, 0xFFFFFF, "isometric");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 130, 0xFFFFFF, "zoom    :");
	ft_nbr_string_put(110, 130, map->size_bloc, map);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 160, 0xFFFFFF, "delta z : ");
	ft_nbr_string_put(110, 160, map->z_height, map);
}
