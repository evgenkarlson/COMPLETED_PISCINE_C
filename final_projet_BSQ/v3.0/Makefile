# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 01:40:11 by lkinzel           #+#    #+#              #
#    Updated: 2017/07/26 23:16:02 by lkinzel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

FLAGS = -Werror -Wall -Wextra

SRC = transformarray.c main.c find_biggest.c transform_to_string.c read_str.c helpers.c

HEADER = bsq.h

$(NAME):
	gcc $(FLAGS) -o $(NAME) $(SRC) libft.a

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all
