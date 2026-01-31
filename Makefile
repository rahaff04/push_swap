NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = main.c \
      stack.c \
	  parsing.c \
	  instruction.c\
	  stack_helpers.c \
	  sort_small.c \

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@if [ ! -d $(LIBFT_DIR) ]; then \
		git clone https://github.com/rahaff04/libftt.git $(LIBFT_DIR); \
	fi
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re