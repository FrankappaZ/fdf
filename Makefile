#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/18 08:34:33 by abureau           #+#    #+#              #
#    Updated: 2016/08/18 08:34:33 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = ./src/mprime.c \
	./src/square_f.c \
	./src/get_dist.c \
	./src/list_func.c \
	./src/color.c \
	./src/m_source.c \
	./src/squaroot.c \
	./src/range.c \
	./src/main.c \
	./src/delta_init.c \
	./src/bres_cases.c \
	./src/bresenham.c \
	./src/line.c \
	./src/rota.c \
	./src/parser.c \
	./src/lists.c

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

re: fclean all
