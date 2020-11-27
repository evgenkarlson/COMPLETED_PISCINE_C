# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flklein <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 17:41:26 by flklein           #+#    #+#              #
#    Updated: 2018/09/16 02:42:03 by flklein          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2

IDIR = includes
_INC = colle-2.h
INC = $(patsubst %,$(IDIR)/%,$(_INC))

SDIR = srcs
_SRC = find_rush.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strcmp.c ft_strjoin.c \
	ft_strlen.c main.c rush00.c rush01.c rush02.c rush03.c rush04.c bonus.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

OBJ = $(_SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
OPTS = -o $(NAME) -I$(IDIR)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		@gcc $(FLAGS) $(OPTS) $(SRC)

$(OBJ): $(SRC)
		@gcc -c -I$(IDIR) $(SRC)

clean:
		@/bin/rm -f $(OBJ)

fclean: clean
		@/bin/rm -f $(NAME)

re: clean all
