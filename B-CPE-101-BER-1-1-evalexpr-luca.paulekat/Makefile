##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## wtf?
##

SRC = 	./infinadd.c \
	./infinsub.c \
	./shared.c \
	./tools.c \
	./infinmul.c \
	./infindiv.c


OBJ = $(SRC:.c=.o)

NAME = eval_expr

TEST_NAME = unit_tests

TEST_SRC =	./tests/test_infinadd.c \
		./tests/test_infinsub.c

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
