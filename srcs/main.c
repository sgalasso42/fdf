/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:24:02 by sgalasso          #+#    #+#             */
/*   Updated: 2019/04/01 23:24:51 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_grid(t_map *map) // todel
{
	int i;

	i = 0;
	while (i < map->nb_y)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

void	ft_free_map(t_map *map) // todel
{
	ft_free_grid(map);
	free(map->params);
	free(map->size_diag);
}


void	ft_error_exit(char *str, t_map *map)
{
	(void)map;
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

int		ft_exit(t_map *map)
{
	ft_free_map(map);
	exit(EXIT_SUCCESS);
}

int		main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		ft_error_exit("Fdf: error, bad args", &map);
	ft_get_map(&map, argv);
	ft_init_fdf(&map);
	ft_display_grid(&map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
