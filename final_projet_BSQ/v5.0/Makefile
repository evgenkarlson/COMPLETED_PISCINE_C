# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 15:11:33 by ecaceres          #+#    #+#              #
#    Updated: 2019/08/21 19:57:49 by fyusuf-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
C_YELLOW_B=\033[1;95m
C_LIGHT_RED_B=\033[0;91m
C_WHITE=\033[0;97m
C_RESET=\033[0;39m

SRCS	= ./srcs/main.c ./srcs/solution.c ./srcs/utilities.c ./srcs/bsq_parse.c ./srcs/bsq_parse2.c ./srcs/bsq_grid.c 
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= bsq
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -g

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

run :
	./${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

norm :
	norminette */*.[ch]

find_sources :
	find srcs -type f -name "*.c" | xargs -I{} echo ./{} | tr '\n' ' '
	
memcheck : re
	/Users/ecaceres/apps/valgrind_3.13_high_sierra/vg-in-place --leak-check=full ./bsq ./tests/set/*
	
memcheck_1 : re
	/Users/ecaceres/apps/valgrind_3.13_high_sierra/vg-in-place --leak-check=full ./bsq ./tests/set/grid_1

check : re
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing set$(C_RESET)" ;
	@./${NAME} ./tests/set/* || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing an empty file$(C_RESET)" ;
	@./${NAME} ./tests/cases/empty_map || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing an invalid map$(C_RESET)" ;
	@./${NAME} ./tests/cases/invalid_map || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing file with no permission$(C_RESET)" ;
	@./${NAME} ./tests/cases/no_permission || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing directory$(C_RESET)" ;
	@./${NAME} ./tests/cases/ || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing 1x1 maps$(C_RESET)" ;
	@./${NAME} ./tests/cases/one_by_one_* || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing maps with irregular width$(C_RESET)" ;
	@./${NAME} ./tests/cases/map_with_irregular_width* || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing maps with invalid header$(C_RESET)" ;
	@./${NAME} ./tests/cases/map_with_invalid_header* || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing maps with invalid height$(C_RESET)" ;
	@./${NAME} ./tests/cases/map_with_invalid_height* || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing a map without any column$(C_RESET)" ;
	@./${NAME} ./tests/cases/no_colomn_line || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing maps with only one column$(C_RESET)" ;
	@./${NAME} ./tests/cases/one_colomn_line* || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing maps with only one line$(C_RESET)" ;
	@./${NAME} ./tests/cases/one_line_colomn* || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing 2x2 maps:$(C_RESET)" ;
	@./${NAME} ./tests/cases/two_by_two* || true ;
	@##

re : fclean all

test : re

.PHONY: all clean fclean re .c.o test
