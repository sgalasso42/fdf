#include "fdf.h"

void	ft_error_exit(char *str, t_map *map)
{
	ft_putendl_fd(str, 2);
	ft_free_grid(map);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(EXIT_FAILURE);
}

int		ft_exit(t_map *map)
{
	ft_free_grid(map);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(EXIT_SUCCESS);
}

int		main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		ft_error_exit("Fdf: error, bad args", &map);
	ft_get_map(&map, argv);
	ft_init_fdf(&map);
	gameloop(&map);
	return (0);
}
