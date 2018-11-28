SRC	=	src/main.c	    	\
		src/init.c		\
		src/useful.c	    	\
		src/error/error.c   	\
		src/parser/parser.c 	\
		src/cmds/create.c   	\
		src/cmds/clone.c    	\
		src/cmds/push.c	    	\
		src/cmds/delete.c   	\
		src/cmds/list.c	    	\
		src/cmds/list-find.c	\
		src/cmds/make.c		\
		src/cmds/perms.c	\
		src/cmds/info.c		\
		src/help.c	    	\
		src/fill.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Iinclude/

NAME	=	repo

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
