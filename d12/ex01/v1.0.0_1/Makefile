# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adespond <adespond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/15 20:02:56 by adespond          #+#    #+#              #
#    Updated: 2015/09/18 06:03:08 by adespond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat

FILE = ./main.c
OBJECT = ./main.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME):
	gcc -c $(FILE)
	gcc $(FLAGS) -o $(NAME) $(OBJECT)

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)
