#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/22 14:34:54 by abureau           #+#    #+#              #
#    Updated: 2016/09/22 14:34:54 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = ./src/atoll.c \
	./src/data.c \
	./src/delta_init.c \
	./src/get_center.c \
	./src/main.c \
	./src/parser.c \
	./src/get_dist.c \
	./src/lists.c \
	./src/square_f.c \
	./src/delta_pos.c \
	./src/definition.c \
	./src/bresenham.c \
	./src/squaroot.c \
	./src/lltoa_base.c \
	./src/m_source.c \
	./src/list_func.c \
	./src/bres_cases.c \
	./src/catch.c \
	./src/color.c \
	./src/mprime.c \
	./src/print.c \
	./src/rota.c

CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Wextra

all: LIBCOMPILE $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ -I libft/includes -L libft/ -lft -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

LIBCOMPILE:
	 make -C libft/

%.o: %.c
	$(CC) $(CFLAGS) -I libft/includes -o $@ -c $<

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
