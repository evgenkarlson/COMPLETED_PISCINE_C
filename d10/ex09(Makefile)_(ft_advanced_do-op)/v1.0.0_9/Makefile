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

SRC = ./srcs/ft_op.c ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_atoi.c ./srcs/ft_putnbr.c 
OBJECT = ./ft_op.o ./ft_putchar.o ./ft_putstr.o ./ft_atoi.o ./ft_putnbr.o

FLAGS = -Wall -Wextra -Werror

all:
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) -o do-op main.c $(SRC)

clean:
	/bin/rm -f $(OBJECT)
