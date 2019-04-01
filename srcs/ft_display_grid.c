/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 04:59:22 by sgalasso          #+#    #+#             */
/*   Updated: 2019/04/01 23:50:25 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_set_grid(t_map *map)
{
	int		i;
	int		j;
	t_vec	vec;

	i = 0;
	map->size_diag->x = (map->nb_x * map->size_bloc) / 2 - map->nb_x;
	map->size_diag->y = (map->nb_y * map->size_bloc) / 4 - map->nb_y;
	while (i < map->nb_y)
	{
		j = 0;
		while (j < map->nb_x)
		{
			ft_calc_coord(&vec, map, i, j);
			j++;
		}
		i++;
	}
}

void	ft_calc_size_map(t_map *map)
{
	map->map_w = map->nb_x * map->size_bloc;
	map->map_h = map->nb_y * ((map->size_bloc + 20) / 2);
	(map->map_w > 1200) ? map->map_w = 1200 : 0;
	(map->map_w < 800) ? map->map_w = 800 : 0;
	(map->map_h > 800) ? map->map_h = 800 : 0;
	(map->map_h < 500) ? map->map_h = 500 : 0;
}

int		ft_display_grid(t_map *map)
{
	ft_calc_size_map(map);
	map->mlx_ptr = mlx_init();

	map->win_ptr = mlx_new_window(map->mlx_ptr, map->map_w, map->map_h, "fdf");
	mlx_do_key_autorepeaton(map->mlx_ptr);
	mlx_hook(map->win_ptr, 2, 0, ft_key, map);
	mlx_hook(map->win_ptr, 17, 0, ft_exit, map);

	display_hud(map);
	ft_set_grid(map);

	mlx_loop(map->mlx_ptr);
	return (1);
}
