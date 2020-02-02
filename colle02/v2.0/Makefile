#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbufnoir <rbufnoir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/07/20 14:32:27 by rbufnoir          #+#    #+#              #
#    Updated: 2014/07/20 23:02:54 by rbufnoir         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
NAME = colle-2
SRC = srcs/ft_colle.c\
	srcs/ft_list.c\
	srcs/ft_string.c\
	srcs/ft_print.c\
	srcs/main.c
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
INC = includes/

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $< -o $@ -I $(INC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
