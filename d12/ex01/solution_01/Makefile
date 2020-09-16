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
LFLAGS = -Wall -Werror -Wextra -o
SOURCE = main.c
HEADER = -I includes/
OBJS = $(patsubst %.c, %.o, $(SOURCE))

all: $(NAME)

$(NAME):
	$(CC) $(LFLAGS) $(NAME) $(SOURCE)

clean:
	/bin/rm -f $(OBJS)

fclean:
	/bin/rm -f $(NAME)

re: fclean all