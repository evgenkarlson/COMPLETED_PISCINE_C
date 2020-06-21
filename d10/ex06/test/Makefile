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

NAME = do-op
CC = gcc
FLAGS = -Werror -Wall -Wextra -o
_SRC = ft_atoi.c ft_putnbr.c ft_putstr.c ft_putchar.c ft_calcs.c ft_do_op.c main.c
SRCS = $(patsubst %, srcs/%, $(_SRC))

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(NAME) $(SRCS)

clean:
	rm -f $(NAME)

re: clean all
