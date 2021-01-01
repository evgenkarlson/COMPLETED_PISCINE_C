# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tclement <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/12 09:33:40 by tclement      #+#    #+#                  #
#    Updated: 2020/02/12 15:45:20 by tclement      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCDIR = srcs

HEADDIR = includes

SRC = $(SRCDIR)/helpers.c \
	  $(SRCDIR)/map.c \
	  $(SRCDIR)/main.c

OBJ = helpers.o \
	  map.o \
	  main.o

all : $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c -I$(HEADDIR) $(SRC)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
