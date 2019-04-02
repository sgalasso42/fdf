# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 16:22:07 by sgalasso          #+#    #+#              #
#    Updated: 2019/04/02 02:22:30 by sgalasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = srcs/main.c \
	  srcs/display_hud.c \
	  srcs/utils.c \
	  srcs/ft_init_fdf.c \
	  srcs/ft_init_struct.c \
	  srcs/ft_get_map.c \
	  srcs/ft_draw.c \
	  srcs/ft_inputs.c \
	  srcs/display_grid.c \
	  srcs/keyboard.c \
	  srcs/gameloop.c \

OBJ = $(SRC:.c=.o)

INCLUDES = includes/

MLX = -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit

all: lib $(NAME)

$(NAME):	$(OBJ)
	gcc -Wall -Wextra -Werror -o $(NAME) libft/libft.a $(OBJ) -I $(INCLUDES) $(MLX)

lib:
	make -C libft/
	make -C minilibx_macos/

%.o: %.c $(INCLUDES)fdf.h Makefile
	gcc -Wall -Wextra -Werror -o $@ -c $< -I $(INCLUDES)

clean:
	rm -f $(OBJ) && make -C libft/ clean

fclean:		clean
	rm -f $(NAME) && make -C libft/ fclean

re:			fclean all

.PHONY : all lib clean fclean re
