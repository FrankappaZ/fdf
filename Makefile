#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/29 15:39:37 by abureau           #+#    #+#              #
#    Updated: 2016/06/29 15:39:37 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = ./src/main.c \
	./src/parser.c \
	./src/lists.c \
	./src/mlx_source.c

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
