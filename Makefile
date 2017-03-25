# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcincean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 13:53:17 by vcincean          #+#    #+#              #
#    Updated: 2017/03/25 14:10:22 by vcincean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = -lft -L libft/ -I libft/
MLX = -lmlx -framework OpenGL -framework AppKit
MATH = -lm

LIB = $(LIBFT) $(MLX) $(MATH)

LIBFT_DIR = libft/
INCLUDES = includes/

SRC = src/main.c src/controller.c src/ft_get_rgb_data.c src/draw_line.c \
	  src/reader.c src/plotter.c src/color_utils.c
OBJ = controller.o ft_get_rgb_data.o reader.o main.o draw_line.o plotter.o \
	  color_utils.o

all: $(NAME)

$(NAME):
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) -c $(SRC) -I $(INCLUDES)
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all
