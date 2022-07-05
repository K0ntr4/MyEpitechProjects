##
## EPITECH PROJECT, 2021
## makefile
## File description:
## creates lib
##

SRC = ./main.c \
	./list_tools.c \
	./list_tools2.c \
	./my_list_size.c \
	./my_params_to_list.c \
	./quicksort.c \
	./swaps.c \
	./swaps2.c \
	./quicksort_move_back.c

NAME = ./push_swap

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
