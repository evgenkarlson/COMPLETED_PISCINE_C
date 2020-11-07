# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/29 14:30:31 by jaleman           #+#    #+#              #
#    Updated: 2016/08/29 14:30:33 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the C compiler to use.
CC := gcc

# Define any compile-time flags.
C_FLAGS =  -Wall -Wextra -Werror

# Define any directories and files containing header files.
INCLS:= ft_bsq.h
INCLDIR = includes/
HEADERS = $(addprefix $(INCLDIR), $(INCLS))

# Define any directories and files containing the source code.
SRCS := ft_auxiliary.c map_helper.c main.c bsq.c
SRCDIR = srcs/
FILES = $(addprefix $(SRCDIR), $(SRCS))

# Define the object files.
OBJS = $(FILES:.c=.o)

# Define the name of the executable file.
TARGET := bsq

all:	$(TARGET)

$(TARGET): $(OBJS)
		$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
		rm -f $(FILES:.c=.o)

fclean:	clean
		rm -f $(TARGET)

re: 	fclean all
