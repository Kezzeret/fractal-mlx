# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchadwic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 17:08:29 by cchadwic          #+#    #+#              #
#    Updated: 2019/10/13 19:35:31 by jkimberl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRC		= ./src/main.c \
		  ./src/draw.c \
		  ./src/fractals.c \
		  ./src/init.c \
		  ./src/keyboard.c \
		  ./src/mouse.c \
		  ./src/draw_right.c \
		  ./src/color.c

OBJ		= $(SRC:.c=.o)

INCLUDE = ./includes

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -O3

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ) $(INCLUDE)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I $(INCLUDE) -L minilibx_macos -lmlx -I minilibx_macos ./libft/libft.a -framework OpenGL -framework AppKit

clean:
	rm -rf $(OBJ)
	$(MAKE) clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all
