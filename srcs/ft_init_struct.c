/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 21:10:28 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/14 14:20:39 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_init_params(t_map *map)
{
	map->params->split = 0;
	map->params->colors = 0;
	map->params->inputs = 0;
	map->params->tx = 0;
	map->params->ty = 0;
	return (1);
}

int		ft_init_map(t_map *map)
{
	if (!(map->grid = (int **)(malloc(sizeof(int *) * 1))))
		return (0);
	map->grid[0] = 0;
	map->nb_y = 0;
	if (!(map->params = (t_params *)(malloc(sizeof(t_params)))))
	{
		free(map->grid);
		return (0);
	}
	map->size_bloc = 40;
	if (!(map->size_diag = (t_pos *)(malloc(sizeof(t_pos)))))
	{
		free(map->grid);
		free(map->params);
		return (0);
	}
	map->map_w = 0;
	map->map_h = 0;
	map->size_diag->x = 0;
	map->size_diag->y = 0;
	map->z_height = 1;
	map->color = 0;
	return (1);
}
