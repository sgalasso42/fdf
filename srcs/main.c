/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:24:02 by sgalasso          #+#    #+#             */
/*   Updated: 2019/04/02 00:47:50 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_exit(char *str, t_map *map)
{
	(void)map;
	// mlx_destroy_window(void *mlx_ptr, void *win_ptr);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

int		ft_exit(t_map *map)
{
	// mlx_destroy_window(void *mlx_ptr, void *win_ptr);
	ft_free_map(map);
	exit(EXIT_SUCCESS);
}

int		main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		ft_error_exit("Fdf: error, bad args", &map);
	ft_get_map(&map, argv);
	ft_init_fdf(&map);
	gameloop(&map);
	return (0);
}
