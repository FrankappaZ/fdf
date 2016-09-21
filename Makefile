#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/19 16:08:51 by abureau           #+#    #+#              #
#    Updated: 2016/09/19 16:08:51 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = ./src/mprime.c \
	./src/square_f.c \
	./src/delta_pos.c \
	./src/data.c \
	./src/get_dist.c \
	./src/list_func.c \
	./src/atoll.c \
	./src/color.c \
	./src/catch.c \
	./src/m_source.c \
	./src/squaroot.c \
	./src/lltoa_base.c \
	./src/main.c \
	./src/delta_init.c \
	./src/bres_cases.c \
	./src/definition.c \
	./src/bresenham.c \
	./src/rota.c \
	./src/parser.c \
	./src/lists.c \
	./src/get_center.c

CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Wextra

.ONESHELL:
all: LIBCOMPILE $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ -I libft/includes -L libft/ -lft -L mlx/ -lmlx -lXext -lX11 -lm -lbsd

LIBCOMPILE:
	make -C libft/

%.o: %.c
	$(CC) $(CFLAGS) -I libft/includes -I mlx -o $@ -c $<

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	./mlx/configure fclean

re: fclean all
