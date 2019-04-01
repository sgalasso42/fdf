#include "fdf.h"

void		make_frame(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	//ft_set_infos(map);
	ft_set_grid(map);
}
