/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:22:31 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/13 19:42:48 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_up(t_map *map)
{
	map->params->ty -= 16;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_set_infos(map);
	ft_set_grid(map);
}

void	ft_key_down(t_map *map)
{
	map->params->ty += 16;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_set_infos(map);
	ft_set_grid(map);
}

void	ft_key_left(t_map *map)
{
	map->params->tx += 16;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_set_infos(map);
	ft_set_grid(map);
}

void	ft_key_right(t_map *map)
{
	map->params->tx -= 16;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_set_infos(map);
	ft_set_grid(map);
}
