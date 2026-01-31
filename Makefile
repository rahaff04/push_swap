NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = main.c \
      init.c \
	  pars/pars.c \
	  pars/pars_split.c \
	  pars/write_error.c \
	  stack_utils/stack.c\
	  stack_utils/stack_helpers.c \
	  sort/sort_small.c \
	  sort/sort_big.c \
	  operations/swap.c \
	  operations/push.c \
	  operations/rotate.c \
	  operations/rev_rotate.c \

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