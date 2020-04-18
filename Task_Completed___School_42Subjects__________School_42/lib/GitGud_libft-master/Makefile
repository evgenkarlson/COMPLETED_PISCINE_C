NAME = libft.a
SRC = 	ft_abs.c \
		ft_atoi.c \
		ft_atoi_base.c \
		ft_bzero.c \
		ft_ctoi.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_iswhitespace.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_pow.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_stradd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_squareplusplus.c \
		ft_strnadd.c \
		ft_lstget.c \
		ft_memadd.c \
		ft_itoc.c \
		ft_putnbr_base.c \
		ft_putnstr.c \
		ft_intlen.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra -I.
ARRC = ar rc
REMOVE = /bin/rm -f
RANLIB = ranlib

.PHONY: clean fclean all re

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC)
	$(ARRC) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

clean:
	$(REMOVE) $(OBJ)

fclean:
	$(REMOVE) $(OBJ) $(NAME)

re: fclean all
