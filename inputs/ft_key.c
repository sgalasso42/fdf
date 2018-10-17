/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:26:45 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/13 19:48:28 by sgalasso         ###   ########.fr       */
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
		ft_key_input(map);
	else if (key == 19)
		ft_key_color(map);
	else if (key == 18)
		ft_key_split(map);
	else if (key == 125)
		ft_key_up(map);
	else if (key == 126)
		ft_key_down(map);
	else if (key == 123)
		ft_key_left(map);
	else if (key == 124)
		ft_key_right(map);
	else if (key == 78)
		ft_key_plus(map);
	else if (key == 69)
		ft_key_minus(map);
	else if (key == 67 || key == 75)
		ft_key_z(key, map);
	return (0);
}
