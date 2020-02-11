# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irhett <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/22 13:13:07 by irhett            #+#    #+#              #
#    Updated: 2016/08/28 23:17:45 by irhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#Compiler Name and Options
CC := gcc
C_FLAGS =  -Wall -Wextra -Werror 

#Filenames
NAME := rush-2
SRCS := main.c make_grid.c shared.c r00c.c r01c.c r02c.c r03c.c r04c.c read_stdin.c
SRCDIR = srcs/
FILES = $(addprefix $(SRCDIR), $(SRCS))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(FILES) -o $(NAME)

clean:
	rm -f $(SRCS:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all
