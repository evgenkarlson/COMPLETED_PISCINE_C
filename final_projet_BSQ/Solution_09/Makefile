# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ple-thie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 23:39:38 by ple-thie          #+#    #+#              #
#    Updated: 2018/07/25 21:07:12 by ple-thie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
CC = gcc
CC_FLAGS = -c -Werror -Wall -Wextra
SOURCES = src/main.c src/file.c src/tools/ft_strcat.c src/tools/ft_putchar.c \
		  src/tools/ft_putstr.c src/tools/ft_atoi.c src/tools/ft_strlen.c \
		  src/tools/ft_strncat.c src/tools/ft_putnbr.c src/converter.c \
		  src/square_finder.c src/tools/ft_map_error.c
OBJ = main.o file.o ft_strcat.o ft_putchar.o ft_putstr.o ft_atoi.o ft_strlen.o \
	  ft_strncat.o ft_putnbr.o converter.o square_finder.o ft_map_error.o

all: $(NAME)

$(NAME):
	$(CC) $(CC_FLAGS) -I includes $(SOURCES)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f grid.txt grid1.txt
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: fclean all grid
	./bsq grid.txt grid1.txt
	cat grid.txt | ./bsq

grid:
	perl tools/generate_grid.pl 10 10 3 > grid.txt
	perl tools/generate_grid.pl 15 15 5 > grid1.txt
