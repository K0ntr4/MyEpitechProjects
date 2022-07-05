##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## wtf?
##

SRC = 	./fstumper.c \
	./prepare.c \
	./validate.c

OBJ = $(SRC:.c=.o)

NAME = rush3

TEST_NAME = unit_tests

TEST_SRC = ./tests/test_fstumper.c

all:    $(NAME)

clean:
	find -regex ".*/.*\.o" -delete;

fclean: clean
	rm $(NAME);
	find -regex ".*/$(TEST_NAME)-.*" -delete;

$(NAME):
	make -C lib/my;
	gcc $(SRC) main.c -o $(NAME) -I include -L lib -l my \
	-g3 -Wall -fno-builtin;

tests_run:
	make -C lib/my;
	gcc $(SRC) $(TEST_SRC) -o $(TEST_NAME) -I include -L lib -l my \
	-g3 -Wall -fno-builtin --coverage -lcriterion -W;
	./$(TEST_NAME)

re: fclean all

.PHONY: all clean
