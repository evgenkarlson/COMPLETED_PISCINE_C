# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/23 18:01:30 by jaleman           #+#    #+#              #
#    Updated: 2016/08/23 18:01:31 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
SRC = srcs/ft_atoi.c srcs/ft_putnbr.c

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -o $(NAME) main.c $(SRC)

clean:
	/bin/rm -f ft_atoi.o ft_putnbr.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
