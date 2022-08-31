NAME := eval_expr

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -o $(NAME) *.c

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re