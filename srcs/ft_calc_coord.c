/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:15:54 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/13 22:08:04 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** - Affichage des points
** - Diagonales
*/

void	ft_calc_diag_line(t_vec *vec, t_map *map, int i, int j)
{
	if (map->params->split == 1 && j < map->nb_x - 1)
	{
		if (vec->c.y != vec->b.y)
		{
			ft_calc_color_cb(vec, map, i, j);
			ft_draw_line(&vec->c, &vec->b, map, vec->color_cb);
		}
		else if (map->grid[i][j] != map->grid[i + 1][j + 1])
		{
			ft_calc_coord_d(vec, map, i, j);
			ft_calc_color_ad(vec, map, i, j);
			ft_draw_line(&vec->a, &vec->d, map, vec->color_ad);
		}
	}
}

void	ft_calc_coord(t_vec *vec, t_map *map, int i, int j)
{
	ft_calc_coord_a(vec, map, i, j);
	if (j < map->nb_x - 1)
	{
		ft_calc_coord_b(vec, map, i, j);
		ft_calc_color_ab(vec, map, i, j);
		ft_draw_line(&vec->a, &vec->b, map, vec->color_ab);
	}
	if (i < map->nb_y - 1)
	{
		ft_calc_coord_c(vec, map, i, j);
		ft_calc_color_ac(vec, map, i, j);
		ft_draw_line(&vec->a, &vec->c, map, vec->color_ac);
		ft_calc_diag_line(vec, map, i, j);
	}
}
