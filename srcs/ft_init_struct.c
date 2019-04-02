/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 21:10:28 by sgalasso          #+#    #+#             */
/*   Updated: 2019/04/02 02:24:20 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_init_params(t_map *map)
{
	map->params.colors = 0;
	map->params.inputs = 0;
	map->params.tx = 0;
	map->params.ty = 0;
	return (1);
}

int		ft_init_map(t_map *map)
{
	if (!(map->grid = (int **)(malloc(sizeof(int *) * 1))))
		return (0);
	map->grid[0] = 0;
	map->nb_y = 0;
	map->size_bloc = 40;
	map->map_w = 0;
	map->map_h = 0;
	map->z_height = 1;
	map->color = 0;
	return (1);
}
