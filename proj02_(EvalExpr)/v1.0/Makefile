# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/23 23:32:23 by lkinzel           #+#    #+#              #
#    Updated: 2017/07/23 23:38:59 by lkinzel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -I header.h -o eval_expr  shuntingyard.c stack.c ft_atoi.c ft_putchar.c ft_strlen.c queue.c ft_strncpy.c calcresult.c ft_putnbr.c main.c helpers.c

re: all
