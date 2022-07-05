##
## EPITECH PROJECT, 2021
## makefile
## File description:
## creates lib
##

SRC = ./main.c \
	./list_tools.c \
	./list_tools2.c \
	./myls.c \
	./get_flags.c \
	./get_rights.c \
	./compare_time.c \
	./my_ls_d.c \
	./my_ls_l.c \
	./alpha_cmp.c

NAME = ./my_ls

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
