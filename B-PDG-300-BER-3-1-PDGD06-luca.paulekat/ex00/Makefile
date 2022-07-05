##
## EPITECH PROJECT, 2021
## makefile
## File description:
## creates lib
##

SRC = ./my_cat.cpp

NAME = ./my_cat

$(NAME): $(OBJ)
		g++ $(SRC) -o $(NAME) -std=c++20 -Wall -Wextra -Werror

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
