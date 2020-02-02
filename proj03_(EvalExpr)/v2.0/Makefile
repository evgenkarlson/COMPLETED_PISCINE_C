# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adespond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/19 06:02:38 by adespond          #+#    #+#              #
#    Updated: 2015/09/20 22:49:04 by adespond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
FLAG = -Wall -Werror -Wextra
FILES = srcs/calculate.c srcs/eval_expr.c srcs/eval_to_btree.c srcs/node.c srcs/str_func.c srcs/btree_create_node.c

all: $(NAME)

$(NAME):
	gcc $(FLAG) -o $(NAME) main.c $(FILES)

clean:
	/bin/rm -f eval_expr

fclean: clean

re: fclean all
