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

NAME = ft_cat
SOURCE = ft_auxiliary.c ft_cat.c
HEADER = ft_lib.h
SRC = $(patsubst %, ./srcs/%, $(SOURCE))
OBJS = $(patsubst %.c, %.o, $(SOURCE))
CFLAGS = -Wall -Werror -Wextra -o

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(NAME) $(SRC) -I $(HEADER)

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all