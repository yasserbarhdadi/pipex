NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

UTILS = ft_split.c ft_printf.c ft_printf_utils.c get_next_line.c req_utils.c req_utils2.c
SRC = $(UTILS) main.c utils.c
SRC_BONUS = $(UTILS) main_bonus.c utils_bonus.c utils2_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

bonus: $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -o $(NAME)
	touch bonus

clean:
	rm -f $(OBJ) $(OBJ_BONUS) bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re