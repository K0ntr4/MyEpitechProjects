##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## wtf?
##

FILES =	./minishell.c \
		./src/environment/setenv.c \
		./src/command_rebuilds/env.c \
		./src/environment/env_tools.c \
		./src/command_rebuilds/cd.c \
		./src/command_rebuilds/tools.c \
		./src/command_rebuilds/cd_verify_directory.c \
		./src/execute/execute_command.c \
		./src/execute/execute_rebuilds.c \
		./src/execute/execute_command_chain.c \
		./src/execute/prepare_command.c \
		./src/execute/prepare_command_helper.c \
		./src/execute/get_path.c \
		./src/execute/norm_input.c

SRC =	./main.c \
		$(FILES)

OBJ =  $(SRC:.c=.o)

NAME =  mysh

TEST_SRC =	$(FILES) \
			./tests/test_my_env.c \
			./tests/test_setenv.c \
			./tests/test_unsetenv.c \
			./tests/test_cd.c \
			./tests/test_env_tools.c \
			./tests/test_un_setenv.c

TEST_OBJ = $(TEST_SRC:.c=.o)

TEST_NAME = unit_tests

CFLAGS =  -I include -L lib -l my

FLAGS = -g3 -Wall -fno-builtin -W

TEST_FLAGS = -g3 -Wall -fno-builtin --coverage -lcriterion -W

all :    $(NAME)

$(NAME) :
			make -C lib/my;
			gcc $(SRC) -o $(NAME) $(CFLAGS) $(FLAGS);
clean:
	find -regex ".*/.*\.o" -delete;

fclean: clean
	find -regex "./$(NAME)" -delete;
	find -regex "./$(NAME)-.*" -delete;
	find -regex ".*/$(TEST_NAME)-.*" -delete;

tests_fclean: clean
	find -regex ".*/$(TEST_NAME)-.*" -delete;

tests_run:
		@make -C lib/my;
		@gcc $(TEST_SRC) -o $(TEST_NAME) $(CFLAGS) $(TEST_FLAGS);
		@make tests_fclean;

re: fclean all


.PHONY: all clean
