# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 01:40:11 by lkinzel           #+#    #+#              #
#    Updated: 2017/07/24 14:53:48 by lkinzel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

FLAGS = -Werror -Wall -Wextra

SRC = calcs.c do_op.c

HEADER = do_op.h
$(NAME):
	gcc $(FLAGS) -o $(NAME) $(SRC) libft.a

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all
