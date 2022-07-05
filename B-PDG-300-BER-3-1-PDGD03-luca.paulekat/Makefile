##
## EPITECH PROJECT, 2021
## makefile
## File description:
## creates lib
##

SRC = ./DoOp.hs

NAME = ./doop

all: 
		ghc $(SRC) -o $(NAME)

clean:
		rm -f $(OBJ)
		rm *.o
		rm *.hi

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
