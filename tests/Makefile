##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## compil unit tests
##

SRC_DIR		=	../src/

OBJECT_DIR	=	../src/manage_object/

UTILS_DIR	=	../src/utils/

SRC	=	$(SRC_DIR)global.c			\
		$(OBJECT_DIR)create_object.c		\
		$(OBJECT_DIR)destroy_object.c		\
		$(UTILS_DIR)check_env.c			\
		$(UTILS_DIR)check_create.c		\
		$(UTILS_DIR)int_to_string.c

SRC_UT	=	test_check_create.c		\
		test_check_env.c		\
		test_int_to_string.c		\
		test_object.c

CCTMP   =       $(SRC:%.c=%.gcno) $(SRC:%.c=%.gcda) $(SRC_UT:%.c=%.gcno) $(SRC_UT:%.c=%.gcda)

LIB	=	-L ../lib/my -lmy -l c_graph_prog -lm

CFLAGS	=	-Wall -Wextra --coverage -fprofile-arcs -ftest-coverage	\
		-I ../include -I ../include/printf

LDFLAGS	=	-lcriterion -lgcov

RM	=	rm -rf

NAME	=	test

CC 	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(SRC) $(SRC_UT) $(LDFLAGS) $(LIB) $(CFLAGS)
		@echo "COMPILATION COMPLETED"

clean:
		$(RM) $(OBJ)
		$(RM) $(CCTMP)
		$(RM) *.g*
		@echo "CLEAN COMPLETED"

fclean:		clean
		$(RM) $(NAME)
		@echo "FCLEAN COMPLETED"

gclean:		fclean
		$(RM) test.info
		$(RM) res

re:		fclean all
