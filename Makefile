# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpalata <cpalata@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/14 14:35:49 by cpalata           #+#    #+#              #
#    Updated: 2026/10/16 13:06:57 by cpalata          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
HEADER = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
OBJ = (SRC=.c=.o)
SRC = rotate.c	swap.c push.c rr_reverse.c

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
