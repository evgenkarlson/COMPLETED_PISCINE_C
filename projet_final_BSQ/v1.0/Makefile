# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpucelle <jpucelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/07/22 13:00:14 by jpucelle          #+#    #+#              #
#    Updated: 2014/07/22 18:19:03 by jpucelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS =
NAME = bsq
_SRC = ft_list.c ft_square.c ft_string.c ft_print.c main.c
SRC = $(patsubst %, src/%, $(_SRC))
_OBJ = $(_SRC:.c=.o)
OBJ = $(patsubst %, obj/%, $(_OBJ))
INC = inc/

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
