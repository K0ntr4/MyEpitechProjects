##
## EPITECH PROJECT, 2021
## makefile
## File description:
## creates lib
##

SRC = ./my_convert_temp.cpp

NAME = ./my_convert_temp

$(NAME): $(OBJ)
		g++ $(SRC) -o $(NAME) -std=c++20 -Wall -Wextra -Werror

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
