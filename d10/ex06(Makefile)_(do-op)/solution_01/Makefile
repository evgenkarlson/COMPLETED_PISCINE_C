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
LFLAGS = -Wall -Wextra -Werror -o
HEADERS = -I includes/
_SRC = ft_do_op.c ft_calc.c ft_putchar.c ft_putstr.c ft_atoi.c ft_putnbr.c main.c
SRCS = $(patsubst %, srcs/%, $(_SRC))


all: $(NAME)

$(NAME):
	$(CC) $(LFLAGS) $(NAME) $(SRCS) $(HEADERS)

clean:
	rm -f $(NAME)

re: clean all
