#!/bin/bash
gcc -Wall -Werror -Wextra -c *.c
ar rc libft.a *.o
ranlib libft.a
