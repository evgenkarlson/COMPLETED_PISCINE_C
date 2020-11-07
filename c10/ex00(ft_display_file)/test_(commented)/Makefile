# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#              #
#    Updated: 2020/11/03 23:19:41 by evgenkarlson     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_display_file
CC := gcc
CFLAGS := -Wall -Werror -Wextra -c
LFLAGS	= -Wall -Werror -Wextra -o
SRC_DIR := ./srcs/
OBJ_DIR	= ./obj/
SRC_FILES := main.c \
			ft_display_file.c \
			ft_strcmp.c \
			ft_putstr.c \
			ft_putchar.c
OBJ_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
HEADER := -I includes/
RM := rm -rf

all: obj $(NAME)

obj: $(SRCS)
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@ $(HEADER)

$(NAME): $(OBJS)
	$(CC) $(LFLAGS) $(NAME) $(OBJS) $(HEADER)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#norm :
#	norminette -R CheckForbiddenSourceHeader */*.[ch]