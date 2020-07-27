# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#              #
#    Created: 2020/02/14 12:33:14 by evgenkarlson     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -c
HEADERS = -I includes/
_SRC = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
SRCS = $(patsubst %, srcs/%, $(_SRC))
OBJS = $(patsubst %.c, %.o, $(_SRC))


all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(LDFLAGS) $(HEADERS) $(SRCS)

	ar rc libft.a $(OBJS)
	ranlib libft.a

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re



# **************************************************************************** #
# **************************************************************************** #
# **************************************************************************** #
