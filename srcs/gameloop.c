#include "fdf.h"

void		make_frame(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	display_hud(map);
	display_grid(map);
}

void		gameloop(t_map *map)
{
	mlx_hook(map->win_ptr, 2, 0, ft_keyboard, map);
	mlx_hook(map->win_ptr, 17, 0, ft_exit, map);
	make_frame(map);
	mlx_loop(map->mlx_ptr);
}
