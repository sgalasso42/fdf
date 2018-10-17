/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 04:59:22 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/13 19:55:30 by sgalasso         ###   ########.fr       */
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

void	ft_set_infos2(t_map *map)
{
	char	*zoom;
	char	*delta;

	delta = 0;
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 130, 0xFFFFFF, "zoom    :");
	if (!(zoom = ft_itoa(map->size_bloc)))
		ft_exit(map);
	if (!(delta = ft_itoa(map->z_height)))
		ft_exit(map);
	mlx_string_put(map->mlx_ptr, map->win_ptr,
	110, 130, 0xFFFFFF, zoom);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 160, 0xFFFFFF, "delta z : ");
	mlx_string_put(map->mlx_ptr, map->win_ptr,
	110, 160, 0xFFFFFF, delta);
	free(zoom);
	free(delta);
}

void	ft_set_infos(t_map *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 10, 0xFFFFFF, "FDF");
	mlx_string_put(map->mlx_ptr, map->win_ptr,
	10, 40, 0xFFFFFF, "press [i] to check inputs");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 70, 0xFFFFFF, "colors  :");
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
	ft_set_infos2(map);
}

void	ft_calc_size_map(t_map *map)
{
	map->map_w = map->nb_x * map->size_bloc;
	map->map_h = map->nb_y * ((map->size_bloc + 20) / 2);
	if (map->map_w > 1200)
		map->map_w = 1200;
	else if (map->map_w < 800)
		map->map_w = 800;
	if (map->map_h > 800)
		map->map_h = 800;
	else if (map->map_h < 500)
		map->map_h = 500;
}

int		ft_display_grid(t_map *map)
{
	map->mlx_ptr = mlx_init();
	ft_calc_size_map(map);
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->map_w, map->map_h, "fdf");
	mlx_do_key_autorepeaton(map->mlx_ptr);
	mlx_hook(map->win_ptr, 2, 0, ft_key, map);
	mlx_hook(map->win_ptr, 17, 0, ft_exit, map);
	ft_set_infos(map);
	ft_set_grid(map);
	mlx_loop(map->mlx_ptr);
	return (1);
}
