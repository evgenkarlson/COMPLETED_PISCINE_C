# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alucas- <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/20 16:16:36 by alucas-           #+#    #+#              #
#    Updated: 2017/07/20 16:16:38 by alucas-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Werror -Wall -Wextra
LDFLAGS=
SRC_DIR=src
INC_DIR=include
NAME=eval_expr
SRC=eval_expr.c \
	ft_putchar.c \
	ft_putnbr.c \
	main.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: $(SRC_DIR)/%.c
	$(CC) -I$(INC_DIR) -o $@ -c $< $(CFLAGS)
	$(CC) -I$(INC_DIR) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
