/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:21:10 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/13 19:46:45 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_plus(t_map *map)
{
	map->size_bloc -= 4;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_set_infos(map);
	ft_set_grid(map);
}

void	ft_key_minus(t_map *map)
{
	map->size_bloc += 4;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_set_infos(map);
	ft_set_grid(map);
}
