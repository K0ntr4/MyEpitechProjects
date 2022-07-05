##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## wtf?
##

FILES =	src/link.c \
		src/read_input.c \
		src/validate_str.c \
		src/parse_input.c \
		src/rooms/get_important_rooms.c \
		src/split_str.c \
		src/handle_comments.c \
		src/show_input.c \
		src/bfs_algorithm/breadth_first_search.c \
		src/bfs_algorithm/queue_tools.c \
		src/bfs_algorithm/init.c \
		src/bfs_algorithm/conditionals.c \
		src/ants/ants.c \
		src/ants/pathing.c \
		src/ants/loging_ant_infos.c \
		src/safety_checks.c \
		src/rooms/loging_room_infos.c \
		src/free_list_validation.c



SRC =	./main.c \
		$(FILES)

OBJ =  $(SRC:.c=.o)

NAME =  lem_in

TEST_SRC =	tests/test_parsing.c \
			$(FILES)

TEST_OBJ = $(TEST_SRC:.c=.o)

TEST_NAME = unit_tests

CFLAGS =  -I include -L lib -l my -g

FLAGS = -g3 -Wall -fno-builtin --coverage -lcriterion -W

all :    $(NAME)

$(NAME) :	$(OBJ)
		make -C lib/my;
		gcc $(OBJ) -o $(NAME) $(CFLAGS);
		@make clean;
clean:
	find -regex ".*/.*\.o" -delete;

fclean: clean
	find -regex "./$(NAME)" -delete;
	find -regex ".*/$(TEST_NAME)-.*" -delete;

tests_fclean: clean
	find -regex ".*/$(TEST_NAME)-.*" -delete;

tests_run:
		@make -C lib/my;
		@gcc $(TEST_SRC) -o $(TEST_NAME) $(CFLAGS) $(FLAGS);
		./unit_tests
		gcovr --exclude tests/
		@make tests_fclean;

re: fclean all


.PHONY: all clean
