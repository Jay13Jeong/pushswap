NAME = push_swap
SRC = main.c orders.c utils.c utils2.c utils3.c utils4.c utils5.c utils6.c utils7.c
OBJ = *.o
HEADER = push_swap.h
LIBFT = libft/libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(FLAGS) -c $(SRC) -I$(HEADER)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	make -C libft clean
	rm -rf ./*.o

fclean: clean
	make -C libft fclean
	rm -rf ./$(NAME)

re: fclean all

.PHONY: all clean fclean re
