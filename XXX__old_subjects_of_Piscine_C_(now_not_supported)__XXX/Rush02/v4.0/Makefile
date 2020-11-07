CC = gcc
NAME = rush-2
FLAG = -Wall -Werror -Wextra
INCLUDE = -I ./include
SRC = srcs/rush_finder.c srcs/lib.c srcs/main.c srcs/all_rushes.c
OUTS = rush_finder.o lib.o main.o all_rushes.o

all: $(NAME)

$(NAME):
	$(CC) $(FLAG) $(INCLUDE) $(SRC) -o $(NAME)

clean:
	rm -f $(OUTS)

fclean: clean
	rm -f $(NAME)

re: fclean all