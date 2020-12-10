# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cromalde <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 18:54:47 by cromalde          #+#    #+#              #
#    Updated: 2020/11/08 18:54:56 by cromalde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c ft_utils.c ft_utils2.c
OBJS	=	${SRCS:.c=.o}
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	rush-02

.c.o:
	${CC} ${CFLAGS} -c $<

all:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

${NAME}:	${OBJS}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean	all

.PHONY:	all clean fclean re