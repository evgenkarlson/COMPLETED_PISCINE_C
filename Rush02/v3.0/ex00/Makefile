# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksticks <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/22 14:01:44 by ksticks           #+#    #+#              #
#    Updated: 2019/06/22 14:01:45 by ksticks          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2
FLAGS = -Wall -Wextra -Werror
HEADER = ./headers/
SRC = ./src/*.c
OPTION = -I $(HEADER)
OBJ = *.o

ALL : $(NAME)

$(NAME) :
	gcc -o $(NAME) $(FLAGS) $(OPTION) $(SRC)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean ALL

