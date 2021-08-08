# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#              #
#    Updated: 2021/04/09 16:19:53 by evgenkarlson     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := bsq
CC := gcc
FLAGS := -Wall -Werror -Wextra
SRC_DIR := ./srcs/
OBJ_DIR	:= ./obj/
SRC_FILES := main.c\
			bsq.c \
			ft_cfg_and_check.c \
			ft_save_fmap_to_arr.c \
			ft_conv_char_arr_to_num.c \
			ft_find_coord_nearest_squar.c \
			ft_paint_over_the_squar.c \
			ft_destroy.c \
			ft_put_map.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_stdin.c

OBJ_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
HEADER := -I includes/
RM := rm -rf

all: obj $(NAME)

obj: $(SRCS)
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@ $(HEADER)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(HEADER)
#	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(HEADER)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

#norm :
#	norminette -R CheckForbiddenSourceHeader */*.[ch]

# символ '@' перед программой ставится для скрытия информации отображающейся этой программой

