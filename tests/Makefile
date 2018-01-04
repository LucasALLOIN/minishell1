##
## EPITECH PROJECT, 2018
## Project mysh
## File description:
## Unit Testing.
##

SRC_DIR	=	../

SRC	=	$(SRC_DIR)source/main.c

U_SRC	=	main_test.c

OBJ	=	$(SRC:.c=.o) $(U_SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -W --coverage -I../include/

LDFLAGS	=	-lcriterion -lgcov

NAME	=	units

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
