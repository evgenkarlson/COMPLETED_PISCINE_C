#!/bin/bash

################################################################################
#
#           1. libft_creator(создаем библиотеку - архив с обьектными файлами) :
#
################################################################################

gcc -Wall -Wextra -Werror -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c -I./
#  ИЛИ ТАК
# 
# for f in *.c; do gcc -Wall -Wextra -Werror -c $f -I./; done

ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

ranlib libft.a

rm *.o
