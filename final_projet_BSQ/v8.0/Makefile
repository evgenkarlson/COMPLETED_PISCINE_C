# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cromalde <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 10:01:27 by cromalde          #+#    #+#              #
#    Updated: 2020/11/12 10:58:20 by cromalde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

SRCS	=	./srcs/main.c \
			./srcs/calcrow.c \
			./srcs/ft_is_valid.c \
			./srcs/ft_findsquare.c \
			./srcs/print.c \
			./srcs/util_functions.c

INC		=	./includes/

OBJS	=	./main.o \
			./calcrow.o \
			./ft_is_valid.o \
			./ft_findsquare.o \
			./print.o \
			./util_functions.o

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	bsq

.PHONY:	all clean fclean re


.c.o:
	${CC} ${CFLAGS} -I ${INC} -c ${SRCS} 
	
${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

${OBJS}:		${SRCS}
	${CC} ${CFLAGS} -I ${INC} -c ${SRCS}

all:	${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

