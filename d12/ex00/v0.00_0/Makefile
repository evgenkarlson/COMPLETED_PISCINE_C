# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/25 10:38:04 by jaleman           #+#    #+#              #
#    Updated: 2016/08/25 10:38:04 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SOURCE = ft_display_file.c ft_display_stdin.c ft_putstr.c ft_strcmp.c main.c
HEADER = ft_lib.h
OBJECTS = ft_display_file.o ft_display_stdin.o ft_putstr.o ft_strcmp.o main.o
CFLAGS = -Wall -Werror -Wextra -o

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(NAME) $(SOURCE) -I $(HEADER)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
