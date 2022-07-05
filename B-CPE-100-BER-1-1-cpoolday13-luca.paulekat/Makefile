##
## EPITECH PROJECT, 2021
## makefile
## File description:
## creates lib
##

SRC = ./btree_create_node.c \
	./btree_apply_prefix.c \
	./btree_apply_infix.c \
	./btree_apply_suffix.c \
	./btree_insert_data.c \
	./btree_search_item.c \
	./btree_level_count.c \
	./btree_apply_by_level.c

OBJ = $(SRC:.c=.o)

NAME = ./libbtree.a

$(NAME): $(OBJ)
		 ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
