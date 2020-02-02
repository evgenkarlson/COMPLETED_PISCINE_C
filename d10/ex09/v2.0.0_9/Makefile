# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 01:40:11 by lkinzel           #+#    #+#              #
#    Updated: 2017/07/25 12:45:34 by lkinzel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_advanced_do-op

FLAGS = -Werror -Wall -Wextra

SRC = calcs.c ft_advanced_do_op.c

$(NAME):
	gcc $(FLAGS) -o $(NAME) $(SRC) libft.a

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all
