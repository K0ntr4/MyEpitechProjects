##
## EPITECH PROJECT, 2021
## makefile
## File description:
## creates lib
##

SRC = ./manage_string_struct.c \
	./manipulate_string.c \
	./init_string_struct.c \
	./get_string.c \
	./find_in_str.c \
	./copy_string.c \
	./insert_in_str.c \
	./get_int_string.c \
	./split_c_string.c \
	./split_s_string.c \
	./my_getnbr.c \
	./print_string.c \
	./join_string.c

NAME = ./libstring.a

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
