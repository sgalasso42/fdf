#include "fdf.h"

void		ft_nbr_string_put(int x, int y, int nb, t_map *map)
{
	char	*tmp;

	if (!(tmp = ft_itoa(nb)))
		ft_error_exit("Fdf: error, nbr_string_put out of memory", map);
	mlx_string_put(map->mlx_ptr, map->win_ptr, x, y, 0xFFFFFF, tmp);
	free(tmp);
}

void	ft_free_grid(t_map *map)
{
	int i;

	i = 0;
	while (i < map->nb_y)
		free(map->grid[i++]);
	free(map->grid);
}

int		*ft_intdup(t_map *map, int *src)
{
	int		*cpy;
	int		i;

	i = 0;
	if (!(cpy = (int *)malloc(sizeof(int) * (map->nb_x))))
		return (0);
	while (i < map->nb_x)
	{
		cpy[i] = src[i];
		i++;
	}
	return (cpy);
}
