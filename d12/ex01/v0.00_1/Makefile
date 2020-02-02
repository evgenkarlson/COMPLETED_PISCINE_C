# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/25 22:51:51 by jaleman           #+#    #+#              #
#    Updated: 2016/08/25 22:51:52 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat
SOURCE = srcs/ft_auxiliary.c ft_cat.c
HEADER = ft_lib.h
OBJECTS = ft_auxiliary.o ft_cat.o
CFLAGS = -Wall -Werror -Wextra -o

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(NAME) $(SOURCE) -I $(HEADER)

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
