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
LDFLAGS = -c -I
HEADERS = includes/
_SRC = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
SRCS = $(patsubst %, srcs/%, $(_SRC))
OBJS = $(patsubst %.c, %.o, $(_SRC))


all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(LDFLAGS) $(HEADERS) $(SRCS)

	ar rc libft.a $(OBJS)
	ranlib libft.a

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re



# **************************************************************************** #
# **************************************************************************** #
# **************************************************************************** #


NAME=libft.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra
SRC= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJ=ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
LDFLAGS=-Iincludes/

all : $(NAME)

$(NAME) :
	gcc $(CFLAGS) -c $(SRC) $(LDFLAGS)
	ar rc $(NAME) $(OBJ)
	ranlib	$(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all



# **************************************************************************** #
# **************************************************************************** #
# **************************************************************************** #
