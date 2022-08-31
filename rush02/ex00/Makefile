NAME := rush-2

SRCS := main.c ft_helpers.c guess_handlers.c input_utils.c rush/rush00.c rush/rush01.c rush/rush02.c rush/rush03.c rush/rush04.c

all: $(NAME)

$(NAME):
	gcc -Werror -Wall -Wextra -o $(NAME) $(SRCS)

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re