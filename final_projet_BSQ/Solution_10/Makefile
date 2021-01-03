#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmutti <cmutti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 13:27:39 by cmutti            #+#    #+#              #
#    Updated: 2015/09/24 19:12:06 by cmutti           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = bsq

SRC = srcs/main.c srcs/fonctions.c srcs/fonctions2.c srcs/ft_start.c \
	  srcs/ft_check_instructions.c srcs/ft_board.c srcs/ft_optimisations.c

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)
clean:
		/bin/rm -f
fclean: clean
		/bin/rm -f $(NAME)
re: fclean all
