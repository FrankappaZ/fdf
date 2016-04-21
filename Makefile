NAME = fdf
CC = gcc
SRC = main.c
LIB_H = -I libft/includes/
LIB = libft/libft.a
CFLAGS = -g -Wall -Werror -Wextra
FLAGS = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(CFLAGS) -c $(LIB_H) $(SRC)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_H) $(LIB) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
