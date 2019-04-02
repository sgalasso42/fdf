/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:24:22 by sgalasso          #+#    #+#             */
/*   Updated: 2019/04/02 03:41:28 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct		s_pos
{
	int x;
	int y;
}					t_pos;

typedef struct		s_vec
{
	t_pos	a;
	t_pos	b;
	t_pos	c;
}					t_vec;

typedef struct		s_params
{
	int		isometric;
	int		inputs;
	int		tx;
	int		ty;
}					t_params;

typedef struct		s_map
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			nb_x;
	int			nb_y;
	int			**grid;
	int			map_w;
	int			map_h;
	int			size_bloc;
	int			z_height;
	t_params	params;
}					t_map;

int					*ft_intdup(t_map *map, int *src); // ?

void				gameloop(t_map *map);
void				display_hud(t_map *map);
void				make_frame(t_map *map);
void				ft_error_exit(char *str, t_map *map);
void				ft_nbr_string_put(int x, int y, int nb, t_map *map);
void				ft_init_fdf(t_map *map);
int					ft_exit(t_map *map);
void				ft_get_map(t_map *map, char **argv);
void				ft_draw_line(t_pos *a, t_pos *b, t_map *map);
void				display_grid(t_map *map);
void				ft_set_inputs(t_map *map);
void				ft_free_grid(t_map *map);
int					ft_keyboard(int key, t_map *map);

#endif
