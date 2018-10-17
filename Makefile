# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 16:22:07 by sgalasso          #+#    #+#              #
#    Updated: 2018/10/17 13:33:34 by sgalasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = srcs/main.c \
	  srcs/ft_intdup.c \
	  srcs/ft_init_struct.c \
	  srcs/ft_get_map.c \
	  srcs/ft_draw.c \
	  srcs/ft_inputs.c \
	  srcs/ft_calc_coord.c \
	  srcs/ft_coord_abcd.c \
	  srcs/ft_calc_color.c \
	  srcs/ft_display_grid.c \
	  inputs/ft_key.c \
	  inputs/ft_key_mode.c \
	  inputs/ft_key_move.c \
	  inputs/ft_key_other.c \
	  inputs/ft_key_z.c \
	  inputs/ft_key_zoom.c \

OBJ = $(SRC:.c=.o)

INCLUDES = includes/

MLX = -lmlx -framework OpenGL -framework AppKit

all: lib $(NAME)

$(NAME):	$(OBJ)
	gcc -Wall -Wextra -Werror -o $(NAME) libft/libft.a $(OBJ) -I $(INCLUDES) $(MLX)

lib:
	make -C libft/

%.o: %.c $(INCLUDES)fdf.h Makefile
	gcc -Wall -Wextra -Werror -o $@ -c $<

clean:
	rm -f $(OBJ) && make -C libft/ clean

fclean:		clean
	rm -f $(NAME) && make -C libft/ fclean

re:			fclean all

.PHONY : all lib clean fclean re
