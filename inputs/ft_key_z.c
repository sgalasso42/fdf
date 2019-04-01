/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:20:47 by sgalasso          #+#    #+#             */
/*   Updated: 2019/04/01 23:59:56 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_zup(t_map *map)
{
	map->z_height += 1;
}

void	ft_key_zdown(t_map *map)
{
	map->z_height -= 1;
}

void	ft_key_z(int key, t_map *map)
{
	if (key == 67)
		ft_key_zup(map);
	else
		ft_key_zdown(map);
}
