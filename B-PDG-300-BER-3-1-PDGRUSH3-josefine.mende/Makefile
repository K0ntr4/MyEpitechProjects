##
## EPITECH PROJECT, 2022
## B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
## File description:
## Makefile
##

SRC	= src/*.cpp

NAME	=	MyGKrellm

INC	=	-I./include/

OBJ	=	$(SRC:.c=.o)

all:	$(NAME) clean

$(NAME):	$(OBJ)
	g++ $(SRC) $(INC) -g3 -o $(NAME) -lncurses -lsfml-graphics -lsfml-window -lsfml-system


	rm -f src/*.o
	rm -f lib/*.o

clean:
	rm -f src/*.o
	rm -f lib/*.o

fclean:	clean
	rm -f $(NAME)
	rm -f a.out

re:	fclean all