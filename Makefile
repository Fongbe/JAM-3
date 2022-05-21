NAME	=	MargesFamilly
SRC		=	$(wildcard grf/*.cpp)
OBJ		=	$(SRC:.cpp=.o)

LDFLAGS	=	-lsfml-system -lsfml-graphics -lsfml-audio -lsfml-window
CFLAGS	=	-Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	re fclean clean all