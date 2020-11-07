# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#              #
#    Updated: 2020/11/04 22:23:46 by evgenkarlson     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_hexdump
CC := gcc
CFLAGS := -Wall -Werror -Wextra -c
LFLAGS	= -Wall -Werror -Wextra -o
SRC_DIR := ./srcs/
OBJ_DIR	= ./obj/
SRC_FILES := concat_strings.c \
			 ft_print_memory.c \
			 get_option.c \
			 print_asterisk.c \
			 print_hex.c \
			 print_line.c \
			 read_file.c \
			 read_single_file.c \
			 file_exists.c \
			 get_file.c \
			 main.c \
			 print_error_message.c \
			 print_hex_line.c \
			 read_argument_files.c \
			 read_input.c  utils.c
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