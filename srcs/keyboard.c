#include "../includes/fdf.h"

void	ft_key_esc(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	ft_exit(map);
}

void	ft_key_space(t_map *map)
{
	map->params->tx = 0;
	map->params->ty = 0;
	map->params->split = 0;
	map->params->colors = 0;
	map->size_bloc = 40;
	map->z_height = 1;
}

int		ft_keyboard(int key, t_map *map)
{
	if (key == 53)
		ft_key_esc(map);
	else if (key == 49)
		ft_key_space(map);
	else if (key == 34)
		map->params->inputs = (map->params->inputs) ? 0 : 1;
	else if (key == 19)
		map->params->colors = (map->params->colors) ? 0 : 1;
	else if (key == 18)
		map->params->split = (map->params->split) ? 0 : 1;
	else if (key == 125)
		map->params->ty -= 16;
	else if (key == 126)
		map->params->ty += 16;
	else if (key == 123)
		map->params->tx += 16;
	else if (key == 124)
		map->params->tx -= 16;
	else if (key == 78)
		map->size_bloc -= 4;
	else if (key == 69)
		map->size_bloc += 4;
	else if (key == 67)
		map->z_height += 1;
	else if (key == 75)
		map->z_height -= 1;
	make_frame(map);
	return (0);
}
