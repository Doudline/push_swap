SRCS =

BONUS =

OBJ = $(SRCS:%c=%o)
OBJ_BONUS = $(BONUS:%c=%o)
CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = push_swap.a
all: $(NAME)
$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
bonus: $(OBJ) $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ) $(OBJ_BONUS)
clean:
	rm -f $(OBJ) $(OBJ_BONUS)
fclean: clean
	rm -f $(NAME)
re: fclean all
