# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#              #
#    Updated: 2020/09/22 02:44:57 by evgenkarlson     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail
CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
LFLAGS = -Wall -Werror -Wextra -o
SOURCE = ft_display_custom_error.c ft_atoi.c ft_get_strerr.c ft_putchar.c ft_putstr.c ft_size_file.c ft_print_name.c ft_display_file.c ft_tail.c main.c
HEADER = -I includes/
SRC = $(patsubst %, ./srcs/%, $(SOURCE))
OBJS = $(patsubst %.c, %.o, $(SOURCE))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC)
	$(CC) $(LFLAGS) $(NAME) $(OBJS) $(HEADER)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all