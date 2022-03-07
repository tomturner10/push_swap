
NAME = push_swap

SRCS =	push_swap.c \
		stack_utils.c \
		operations.c \
		operations_extra.c \
		large_sort.c \
		small_sort.c \
		normalize.c

FLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) -I libft libft/libft.a $(SRCS) -o push_swap

clean:
	$(MAKE) clean -C ./libft
	rm -f

fclean:
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re