##
## EPITECH PROJECT, 2021
## makefile
## File description:
## creates lib
##

SRC =	./main.c \
		./my_puterror.c \
		./operations.c

OBJ = $(SRC:.c=.o)

NAME = do-op

$(NAME): $(OBJ)
		gcc $(OBJ) -o $(NAME) -lmy -L ./../lib

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
