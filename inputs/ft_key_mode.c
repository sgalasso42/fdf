/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:23:40 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/13 19:42:28 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_input(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	if (map->params->inputs == 0)
	{
		map->params->inputs = 1;
		ft_set_inputs(map);
	}
	else
	{
		map->params->inputs = 0;
		ft_set_infos(map);
		ft_set_grid(map);
	}
}

void	ft_key_color(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	if (map->params->colors == 0)
		map->params->colors = 1;
	else
		map->params->colors = 0;
	ft_set_infos(map);
	ft_set_grid(map);
}

void	ft_key_split(t_map *map)
{
	if (map->params->split == 1)
		map->params->split = 0;
	else
		map->params->split = 1;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_set_infos(map);
	ft_set_grid(map);
}
