##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make file gcc with flag basic
##

SRC =		main.c \
			fonction_attribute.c \
			lib.c \
			file2.c



SRCTEST = 	test_main.c \
			tests/test_exit_bsq.c 

OBJ = $(SRC:.c=.o)

OBJTEST = $(SRCTEST:.c=.o)

NAME =	bsq

TESTFLAG = -lcriterion --coverage

NAMETEST = unit_tests

CFLAGS =  -Wall -Wextra -W -pedantic -C -O3

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

tests_run: $(NAMETEST)

$(NAMETEST): $(OBJTEST)
	gcc $(TESTFLAG) $(OBJTEST) -o $(NAMETEST)

test_clean: 
	rm -rf $(OBJTEST)

test_fclean: clean
	rm -rf $(NAMETEST)

re_test: test_fclean test_run