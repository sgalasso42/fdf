/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:20:47 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/13 19:48:10 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_zup(t_map *map)
{
	map->z_height += 1;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_set_infos(map);
	ft_set_grid(map);
}

void	ft_key_zdown(t_map *map)
{
	map->z_height -= 1;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_set_infos(map);
	ft_set_grid(map);
}

void	ft_key_z(int key, t_map *map)
{
	if (key == 67)
		ft_key_zup(map);
	else
		ft_key_zdown(map);
}
