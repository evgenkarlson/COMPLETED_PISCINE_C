# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksticks <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/23 13:37:01 by ksticks           #+#    #+#              #
#    Updated: 2019/06/23 13:37:02 by ksticks          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
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

