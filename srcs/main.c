/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:24:02 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/14 15:03:29 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_grid(t_map *map)
{
	int i;

	i = 0;
	while (i < map->nb_y)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

void	ft_free_map(t_map *map)
{
	ft_free_grid(map);
	free(map->params);
	free(map->size_diag);
}

int		ft_exit(t_map *map)
{
	ft_free_map(map);
	exit(1);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	fd = 0;
	if (argc != 2)
		ft_putendl("Error : wrong numbers of arguments");
	else if (!ft_get_map(&map, argv, fd))
		ft_putendl("Error : can't get the map");
	else
	{
		if (!ft_display_grid(&map))
			ft_putendl("Error : can't display the grid");
		ft_free_map(&map);
	}
	return (0);
}
