#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schapuis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/08/29 13:25:39 by schapuis          #+#    #+#              #
#    Updated: 2013/08/29 13:28:55 by schapuis         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_cat

SRC = ft_cat.c

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	gcc -o $(NAME) ft_cat.o

clean:
	/bin/rm -f ft_cat.o

fclean:
	/bin/rm -f $(NAME)

re:
	fclean all
