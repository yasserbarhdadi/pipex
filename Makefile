NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

UTILS = ft_split.c ft_printf.c ft_printf_utils.c get_next_line.c req_utils.c req_utils2.c
SRC = $(UTILS) main.c utils.c
SRC_BONUS = $(UTILS) main_bonus.c utils_bonus.c utils2_bonus.c

all: $(NAME) $(SRC)

bonus: clean $(NAME) $(SRC_BONUS)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(NAME_BONUS): $(SRC_BONUS)
	$(CC) $(CFLAGS) $(SRC_BONUS) -o $(NAME_BONUS)

clean:
	@rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus