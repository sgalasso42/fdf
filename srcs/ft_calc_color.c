/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:56:13 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/13 20:00:02 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_select_color(int val)
{
	int		res;
	int		r;
	int		g;
	int		b;

	val++;
	res = 0;
	r = R_MIN + val * R_DELTA;
	g = G_MIN + val * G_DELTA;
	b = B_MIN + val * B_DELTA;
	res += r << 8;
	res += g << 4;
	res += b;
	return (res);
}

void	ft_calc_color_ab(t_vec *vec, t_map *map, int i, int j)
{
	int		higher;

	higher = 0;
	vec->color_ab = 0xFFFFFF;
	if (map->params->colors == 1)
	{
		higher = (map->grid[i][j] < map->grid[i][j + 1])
		? map->grid[i][j + 1] : map->grid[i][j];
		if (higher > 10)
			higher = 10;
		if (higher > 0)
			vec->color_ab = ft_select_color(higher);
		else
			vec->color_ab = 0x74D2;
	}
}

void	ft_calc_color_ac(t_vec *vec, t_map *map, int i, int j)
{
	int		higher;

	higher = 0;
	vec->color_ac = 0xFFFFFF;
	if (map->params->colors == 1)
	{
		higher = (map->grid[i][j] < map->grid[i + 1][j])
		? map->grid[i + 1][j] : map->grid[i][j];
		if (higher > 10)
			higher = 10;
		if (higher > 0)
			vec->color_ac = ft_select_color(higher);
		else
			vec->color_ac = 0x74D2;
	}
}

void	ft_calc_color_cb(t_vec *vec, t_map *map, int i, int j)
{
	int		higher;

	higher = 0;
	vec->color_cb = 0xFFFFFF;
	if (map->params->colors == 1)
	{
		higher = (map->grid[i + 1][j] < map->grid[i][j + 1])
		? map->grid[i][j + 1] : map->grid[i + 1][j];
		if (higher > 10)
			higher = 10;
		if (higher > 0)
			vec->color_cb = ft_select_color(higher);
		else
			vec->color_cb = 0x74D2;
	}
}

void	ft_calc_color_ad(t_vec *vec, t_map *map, int i, int j)
{
	int		higher;

	higher = 0;
	vec->color_ad = 0xFFFFFF;
	if (map->params->colors == 1)
	{
		higher = (map->grid[i][j] < map->grid[i + 1][j + 1])
		? map->grid[i + 1][j + 1] : map->grid[i][j];
		if (higher > 10)
			higher = 10;
		if (higher > 0)
			vec->color_ad = ft_select_color(higher);
		else
			vec->color_ad = 0x74D2;
	}
}
