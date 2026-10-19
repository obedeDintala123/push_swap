# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/14 14:35:49 by cpalata           #+#    #+#              #
#    Updated: 2026/10/19 20:14:04 by obdintal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = disorder.c \
	main.c \
	push.c \
	rotate.c \
	reverse.c \
	swap.c \
	utils.c \
	utils_second.c \
	validate_number.c \
	validate_option.c \
	stack.c \

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
