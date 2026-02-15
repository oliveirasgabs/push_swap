NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source files
SRCS = main.c \
		handle_errors.c \
		init_a_to_b.c \
		init_b_to_a.c \
		init_stack.c \
		stack_utils.c \
		commands/push.c \
		commands/rev_rotate.c \
		commands/rotate.c \
		commands/sort_stacks.c \
		commands/sort_three.c \
		commands/swap.c

OBJECTS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "Compiling $(LIBFT_DIR)..."
	@$(MAKE) -C $(LIBFT_DIR) bonus

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -L$(LIBFT_DIR) -lft

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJECTS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Cleaning executable..."
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
