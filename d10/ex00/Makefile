# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#              #
#    Created: 2020/02/14 12:33:14 by evgenkarlson     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CC = gcc

CFLAGS = -Wall -Wextra -Werror
CFLAGS = -c -Wall -Wextra -Werror -Iincludes

SRC = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c \
	  ./srcs/ft_strlen.c ./srcs/ft_swap.c
_SRC = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
SRCS = $(patsubst %, srcs/%, $(_SRCS)) 

OBJS = ./ft_putchar.o ./ft_putstr.o ./ft_strcmp.o ./ft_strlen.o ./ft_swap.o
OBJS = $(_SRCS:.c=.o)


HEADER = ./includes/
HEADERS = includes/ft.h

OPTIONS = -c -I ./includes/

all: $(NAME)

 $(NAME):
	$(CC) -c $(CFLAGS) -I=$(HEADER) $(SRC)
	$(CC) $(CFLAGS) $(OPTIONS) $(SRC)
	$(CC) -c $(CFLAGS) $(FILES) -I $(HEADERS)

	ar rc libft.a $(OBJS)
	ranlib libft.a

clean:
	/bin/rm -f ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
clean:
	/bin/rm -f $(OBJS)
clean:
	rm -f $(OBJS)

fclean: clean
	/bin/rm -f  $(NAME)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
