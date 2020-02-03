# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/28 11:36:30 by jaleman           #+#    #+#              #
#    Updated: 2016/08/28 11:36:30 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Compiler Name and Options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -o

#Filenames
NAME = eval_expr
SRCS = ft_auxilary.c eval_expr.c
OBJS = $(FILENAMES:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(NAME) $(addprefix srcs/, $(SRCS))

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
