/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:24:22 by sgalasso          #+#    #+#             */
/*   Updated: 2019/04/02 00:48:42 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>

# define R_MIN 89
# define G_MIN 229
# define B_MIN 99

# define R_DELTA 14
# define G_DELTA -14
# define B_DELTA -1

typedef struct		s_pos
{
	int x;
	int y;
}					t_pos;

/*
**	A---B
**	|	|
**	C---D
*/

typedef struct		s_vec
{
	t_pos	a;
	t_pos	b;
	t_pos	c;
	t_pos	d;
	int		color_ab;
	int		color_ac;
	int		color_cb;
	int		color_ad;
}					t_vec;

typedef struct		s_params
{
	int		split;
	int		colors;
	int		inputs;
	int		tx;
	int		ty;
}					t_params;

/*
** - nb_x nb_y : nombre de noeuds
** - size_bloc : distance entre les noeuds
** - size_diag : valeur de dimension de la grille
** - z_height  : coef de hauteur
*/

typedef struct		s_map
{
	int			map_w;
	int			map_h;
	int			**grid;
	int			nb_x;
	int			nb_y;
	void		*mlx_ptr;
	void		*win_ptr;
	t_params	*params;
	int			size_bloc;
	t_pos		*size_diag;
	int			z_height;
	int			color;
}					t_map;

void				gameloop(t_map *map);
void				display_hud(t_map *map);
void				make_frame(t_map *map);
void				ft_error_exit(char *str, t_map *map);
void				ft_nbr_string_put(int x, int y, int nb, t_map *map);
void				ft_init_fdf(t_map *map);
int					ft_exit(t_map *map);
int					*ft_intdup(t_map *map, int *src);
int					ft_init_params(t_map *map);
int					ft_init_map(t_map *map);
int					ft_get_map(t_map *map, char **argv);
int					ft_check_map(t_map *map);
void				ft_draw_line(t_pos *a, t_pos *b, t_map *map, int color);
void				display_grid(t_map *map);
void				ft_set_inputs(t_map *map);
void				ft_free_grid(t_map *map);
void				ft_free_map(t_map *map);

void				ft_calc_coord(t_vec *vec, t_map *map, int i, int j);
void				ft_calc_coord_a(t_vec *vec, t_map *map, int i, int j);
void				ft_calc_coord_b(t_vec *vec, t_map *map, int i, int j);
void				ft_calc_coord_c(t_vec *vec, t_map *map, int i, int j);
void				ft_calc_coord_d(t_vec *vec, t_map *map, int i, int j);

int					ft_select_color(int val);
void				ft_calc_color_ab(t_vec *vec, t_map *map, int i, int j);
void				ft_calc_color_ac(t_vec *vec, t_map *map, int i, int j);
void				ft_calc_color_cb(t_vec *vec, t_map *map, int i, int j);
void				ft_calc_color_ad(t_vec *vec, t_map *map, int i, int j);

int					ft_keyboard(int key, t_map *map);

#endif
