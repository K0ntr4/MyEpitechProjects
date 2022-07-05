##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## wtf?
##

SRC =   ../count_letters.c ../generate_data_array.c ../letters_in_str.c ../predict_language.c

OBJ = $(SRC:.c=.o)

NAME = rush2

TEST_NAME = unit_tests

all:    $(NAME)

$(NAME):
	gcc $(SRC) ../main.c -o ../$(NAME) -I ../include -L ../lib -l my -g3 -Wall -fno-builtin

tests_run:
	gcc $(SRC) ../tests/test*.c -o ../$(TEST_NAME) -I ../include -L ../lib -l my -g3 -Wall -fno-builtin -W --coverage -lcriterion;

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME);

re: fclean all

.PHONY: all clean fclean re
