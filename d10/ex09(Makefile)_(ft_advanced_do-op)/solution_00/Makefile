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

CC = gcc
LFLAGS = -Werror -Wall -Wextra -o
NAME = ft_advanced_do-op
_SRC = ft_atoi.c ft_putnbr.c ft_putstr.c ft_putchar.c ft_opp.c ft_adv_opp.c main.c
SRCS = $(patsubst %, srcs/%, $(_SRC))

all: $(NAME)

$(NAME):
	$(CC) $(LFLAGS) $(NAME) $(SRCS)

clean:
	rm -f $(NAME)

re: fclean all