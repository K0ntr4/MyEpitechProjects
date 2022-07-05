##
## EPITECH PROJECT, 2021
## makefile
## File description:
## creates lib
##

SRC = ./cat.c \
	./main.c \
	./output_error.c

NAME = ./cat

$(NAME): $(OBJ)
		 $(MAKE) -C ../lib/my/
		 gcc $(SRC) -o $(NAME) -L ../lib/my -l my

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
