##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Day 10
##

SRC =	*.c

OBJ = $(SRC:.c=.o)

NAME = test

LIBMY = libmy.a

MYH = my.h

all:	buildlib cplib cph

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

buildlib:	$(SRC)
	gcc -c $(SRC) -w
	ar rc libmy.a $(OBJ)

cplib:	$(LIBMY)
	cp $(LIBMY) ../

cph:	$(MYH)
	cp $(MYH) ../../include/

clean:
	rm -f *.o
