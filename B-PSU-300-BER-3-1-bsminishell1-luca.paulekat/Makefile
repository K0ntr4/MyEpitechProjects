##
## EPITECH PROJECT, 2021
## makefile
## File description:
## creates lib
##

SRC = ./main.c \
	./exec_print.c

NAME = ./my_exec

$(NAME):
		make -C lib/my;
		gcc $(SRC) -o $(NAME) -I include -L lib -l my -g

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
