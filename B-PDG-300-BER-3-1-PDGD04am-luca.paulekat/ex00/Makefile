##
## EPITECH PROJECT, 2021
## makefile
## File description:
## creates lib
##

SRC = ./z.c

NAME = ./z

$(NAME):
		gcc $(SRC) -o $(NAME) -std=gnu17 -Wall -Wextra

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
