/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:26:45 by sgalasso          #+#    #+#             */
/*   Updated: 2019/04/02 00:05:23 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_key(int key, t_map *map)
{
	if (key == 53)
		ft_key_esc(map);
	else if (key == 49)
		ft_key_space(map);
	else if (key == 34)
		map->params->inputs = (map->params->inputs) ? 0 : 1;
	else if (key == 19)
		map->params->colors = (map->params->colors) ? 0 : 1;
	else if (key == 18)
		map->params->split = (map->params->split) ? 0 : 1;
	else if (key == 125)
		map->params->ty -= 16;
	else if (key == 126)
		map->params->ty += 16;
	else if (key == 123)
		map->params->tx += 16;
	else if (key == 124)
		map->params->tx -= 16;
	else if (key == 78)
		ft_key_plus(map);
	else if (key == 69)
		ft_key_minus(map);
	else if (key == 67 || key == 75)
		ft_key_z(key, map);
	make_frame(map);
	return (0);
}
