##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## wtf?
##

SRC =	./tooltips/help.c \
	./parse/list_tools.c \
	./parse/list_tools2.c \
	./parse/parser_tools.c \
	./parse/parser.c \
	./parse/ast_tools.c \
	./parse/operator_tools.c \
	./parse/parser_get_items.c \
	./parse/to_decimal.c \
	./parse/to_base.c \
	./evaluate/eval_expr.c \
	./evaluate/eval_tree.c \
	./evaluate/infinadd.c \
	./evaluate/infinsub.c \
	./evaluate/infinmul.c \
	./evaluate/infindiv.c \
	./evaluate/infinmod.c \
	./evaluate/shared.c \
	./evaluate/tools.c \
	./evaluate/remove_leading_zeros.c \
	./evaluate/handle_div_array.c \
	./prepare/substitute.c \
	./prepare/validate.c \
	./prepare/delimiters.c \
	./prepare/tools.c \
	./prepare/validate_args.c \
	./prepare/validate_characters.c \
	./bistromatic.c

OBJ = $(SRC:.c=.o)

NAME = calc

TEST_NAME = unit_tests

TEST_SRC =	./tests/test_evaluate.c \
		./tests/test_substitute.c \
		./tests/test_infinsub.c \
		./tests/test_infinadd.c \
		./tests/test_infinmul.c \
		./tests/test_infindiv.c \
		./tests/test_infinmod.c \
		./tests/test_bistromatic.c

FLAGS = -I include -L lib -l my \
	-g3 -Wall -fno-builtin --coverage -lcriterion -W

all:    $(NAME)

clean:
	find -regex ".*/.*\.o" -delete;

fclean: clean
	find -regex "./$(NAME)" -delete;
	find -regex ".*/$(TEST_NAME)-.*" -delete;

$(NAME):
	make -C lib/my;
	gcc main.c $(SRC) -o $(NAME) -I include -L lib -l my \
	-g3 -Wall -fno-builtin -W;

tests_run:
	make -C lib/my
	make fclean;
	gcc $(SRC) $(TEST_SRC) -o $(TEST_NAME) $(FLAGS);
	./$(TEST_NAME)

tests_evaluate:
	echo "Testing Evaluate:"
	make -C lib/my -s;
	make fclean -s;
	gcc $(SRC) ./tests/test_evaluate.c -o $(TEST_NAME) $(FLAGS);
	./$(TEST_NAME)

tests_substitute:
	echo "Testing Substitute:"
	make -C lib/my -s;
	make fclean -s;
	gcc $(SRC) ./tests/test_substitute.c -o $(TEST_NAME) $(FLAGS);
	./$(TEST_NAME)

tests_infinsub:
	echo "Testing Infinsub:"
	make -C lib/my -s;
	make fclean -s;
	gcc $(SRC) ./tests/test_infinsub.c -o $(TEST_NAME) $(FLAGS);
	./$(TEST_NAME)

tests_infinadd:
	echo "Testing Infinadd:"
	make -C lib/my -s;
	make fclean -s;
	gcc $(SRC) ./tests/test_infinadd.c -o $(TEST_NAME) $(FLAGS);
	./$(TEST_NAME)

tests_infinmul:
	echo "Testing Infinadd:"
	make -C lib/my -s;
	make fclean -s;
	gcc $(SRC) ./tests/test_infinmul.c -o $(TEST_NAME) $(FLAGS);
	./$(TEST_NAME)

tests_all:
	@make tests_evaluate -s;
	@make tests_substitute -s;
	@make tests_infinsub -s;
	@make tests_infinadd -s;
	@make tests_infinmul -s;

re: fclean all

.PHONY: all clean
