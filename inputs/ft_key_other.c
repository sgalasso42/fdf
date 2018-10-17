/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:25:31 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/13 22:34:23 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_esc(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	ft_exit(map);
}

void	ft_key_space(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	map->params->tx = 0;
	map->params->ty = 0;
	map->params->split = 0;
	map->params->colors = 0;
	map->size_bloc = 40;
	map->z_height = 1;
	ft_set_infos(map);
	ft_set_grid(map);
}
