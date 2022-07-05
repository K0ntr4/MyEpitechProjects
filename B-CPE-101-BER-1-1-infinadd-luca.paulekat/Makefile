##
## EPITECH PROJECT, 2021
## makefile
## File description:
## creates lib
##

SRC = ./main.c \
	./print_tree.c \
	./addition.c \
	./norm_strings.c \
	./btree_create_node.c \
	./substitution.c \
	./free_tree.c

OBJ = $(SRC:.c=.o)

NAME = ./infin_add

$(NAME): $(OBJ)
		 $(MAKE) -C lib/my/
		 gcc -o $(NAME) $(OBJ) -L lib/my -l my -g

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
