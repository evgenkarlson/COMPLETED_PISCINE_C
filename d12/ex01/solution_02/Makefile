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
CC = gcc
LFLAGS = -Wall -Wextra -Werror -o
SRC = main.c
OBJS = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(NAME) $(SRC)

clean:
	/bin/rm -f $(OBJ)

fclean: 
	/bin/rm -f $(NAME)

re: fclean all