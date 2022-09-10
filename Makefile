# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 11:39:26 by jhoule-l          #+#    #+#              #
#    Updated: 2022/09/07 12:00:43 by jhoule-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c push_swap_args.c push_swap_utils.c push_swap_utils_2.c \

OBJ = $(SRCS:%c=%o)
CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = push
all: $(NAME)
$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
