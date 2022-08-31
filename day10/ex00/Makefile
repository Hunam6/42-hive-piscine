NAME := libft.a

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c srcs/*.c -I includes/*.h
	ar crs $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re all
