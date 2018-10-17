/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 18:34:36 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/13 19:15:50 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_set_inputs(t_map *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr,
	10, 10, 0xFFFFFF, "FDF - INPUTS");
	mlx_string_put(map->mlx_ptr, map->win_ptr,
	10, 40, 0xFFFFFF, "[i]             = inputs");
	mlx_string_put(map->mlx_ptr, map->win_ptr,
	10, 70, 0xFFFFFF, "[1!]            = split mode");
	mlx_string_put(map->mlx_ptr, map->win_ptr,
	10, 100, 0xFFFFFF, "[2@]            = colors");
	mlx_string_put(map->mlx_ptr, map->win_ptr,
	10, 130, 0xFFFFFF, "[+] [-]         = zoom");
	mlx_string_put(map->mlx_ptr, map->win_ptr,
	10, 160, 0xFFFFFF, "[/] [*]         = delta z");
	mlx_string_put(map->mlx_ptr, map->win_ptr,
	10, 190, 0xFFFFFF, "[space bar]     = reset");
	mlx_string_put(map->mlx_ptr, map->win_ptr,
	10, 220, 0xFFFFFF, "[^] [>] [v] [<] = move");
	mlx_string_put(map->mlx_ptr, map->win_ptr,
	10, 250, 0xFFFFFF, "[ESC]           = exit");
	mlx_string_put(map->mlx_ptr, map->win_ptr,
	10, 280, 0xFFFFFF, "[red cross]     = exit");
}
