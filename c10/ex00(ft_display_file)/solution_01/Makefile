# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#              #
#    Updated: 2020/11/03 23:28:33 by evgenkarlson     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
LFLAGS = -Wall -Werror -Wextra -o
SOURCE = main.c
OBJS = $(patsubst %.c, %.o, $(SOURCE))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCE)
	$(CC) $(LFLAGS) $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all