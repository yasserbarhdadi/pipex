CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

UTILS = ft_split.c ft_printf.c ft_printf_utils.c get_next_line.c req_utils.c req_utils2.c
SRC = $(UTILS) main.c utils.c
SRC_BONUS = $(UTILS) main_bonus.c utils_bonus.c utils2_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

bonus: $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -o $(NAME)
	touch bonus

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) bonus

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ) $(OBJ_BONUS)