# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 13:27:39 by cmutti            #+#    #+#              #
#    Updated: 2021/03/10 00:19:31 by evgenkarlson     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC =	srcs/main.c srcs/fonctions.c \
		srcs/ft_start.c \
		srcs/ft_check_instructions.c \
		srcs/ft_board.c \
		srcs/ft_optimisations.c

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)
clean:
		/bin/rm -f
fclean: clean
		/bin/rm -f $(NAME)
re: fclean all
