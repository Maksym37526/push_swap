NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

OBJ_DIR = obj

COMMANDS_SRC = commands/push.c commands/swap.c commands/rotations.c commands/rev_rotate.c
INIT_SRC = init/stack_init.c init/split.c init/nodes.c init/init_a_to_b.c
SORT_SRC = sort/sort_stacks.c sort/moves.c 
UTILS_SRC = utils/stack_utils.c utils/find.c utils/prep.c
ERRORS_SRC = errors/handle_errors.c
MAIN_SRC = main.c

SRCS = $(MAIN_SRC) $(COMMANDS_SRC) $(INIT_SRC) $(SORT_SRC) $(UTILS_SRC) $(ERRORS_SRC)

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re