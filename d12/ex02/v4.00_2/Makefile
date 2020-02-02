#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schapuis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/08/29 14:43:38 by schapuis          #+#    #+#              #
#    Updated: 2013/08/29 14:51:06 by schapuis         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_tail

SRC = ft_tail.c

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	gcc -o $(NAME) ft_tail.o

clean:
	/bin/rm -f ft_tail.o

fclean:
	/bin/rm -f $(NAME)

re:
	fclean all
