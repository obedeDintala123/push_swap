NAME = push_swap

SRC = option.c utils.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all:
	$(MAKE) -C libft
	$(MAKE) -C ft_printf
	$(MAKE) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -Lft_printf -lftprintf -o $(NAME)

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re