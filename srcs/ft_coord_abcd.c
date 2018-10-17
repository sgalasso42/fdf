/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord_abcd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 20:05:31 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/13 22:23:50 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Fonctions de calcul des coordonnees
** - Positionnement iso
** - centrage + translations x y
** - gestion z + delta z
*/

void	ft_calc_coord_a(t_vec *vec, t_map *map, int i, int j)
{
	vec->a.x = (j - i) * (map->size_bloc / 2);
	vec->a.y = (j + i) * (map->size_bloc / 4);
	vec->a.x += map->map_w / 2 + map->params->tx;
	vec->a.y += map->map_h / 2 + map->params->ty - map->size_diag->y;
	vec->a.y -= ((map->grid[i][j] * map->z_height) * (map->size_bloc / 4));
}

void	ft_calc_coord_b(t_vec *vec, t_map *map, int i, int j)
{
	vec->b.x = ((j + 1) - i) * (map->size_bloc / 2);
	vec->b.y = ((j + 1) + i) * (map->size_bloc / 4);
	vec->b.x += map->map_w / 2 + map->params->tx;
	vec->b.y += map->map_h / 2 + map->params->ty - map->size_diag->y;
	vec->b.y -= ((map->grid[i][j + 1] * map->z_height) * (map->size_bloc / 4));
}

void	ft_calc_coord_c(t_vec *vec, t_map *map, int i, int j)
{
	vec->c.x = (j - (i + 1)) * (map->size_bloc / 2);
	vec->c.y = (j + (i + 1)) * (map->size_bloc / 4);
	vec->c.x += map->map_w / 2 + map->params->tx;
	vec->c.y += map->map_h / 2 + map->params->ty - map->size_diag->y;
	vec->c.y -= ((map->grid[i + 1][j] * map->z_height) * (map->size_bloc / 4));
}

void	ft_calc_coord_d(t_vec *vec, t_map *map, int i, int j)
{
	vec->d.x = ((j + 1) - (i + 1)) * (map->size_bloc / 2);
	vec->d.y = ((j + 1) + (i + 1)) * (map->size_bloc / 4);
	vec->d.x += map->map_w / 2 + map->params->tx;
	vec->d.y += map->map_h / 2 + map->params->ty - map->size_diag->y;
	vec->d.y -= ((map->grid[i + 1][j + 1]
	* map->z_height) * (map->size_bloc / 4));
}
