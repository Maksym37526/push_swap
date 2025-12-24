NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRC_DIR = src
OBJ_DIR = obj

COMMANDS_DIR = $(SRC_DIR)/commands
COMMANDS_SRC = push.c swap.c rotations.c rev_rotate.c

INIT_DIR = $(SRC_DIR)/init
INIT_SRC = stack_init.c split.c nodes.c init_a_to_b.c

SORT_DIR = $(SRC_DIR)/sort
SORT_SRC = sort_stacks.c  moves.c 

UTILS_DIR = $(SRC_DIR)/utils
UTILS_SRC = stack_utils.c find.c prep.c

ERRORS_DIR = $(SRC_DIR)/errors
ERRORS_SRC = handle_errors.c

SRCS = $(SRC_DIR)/main.c \
	$(addprefix $(COMMANDS_DIR)/, $(COMMANDS_SRC)) \
	$(addprefix $(INIT_DIR)/, $(INIT_SRC)) \
	$(addprefix $(SORT_DIR)/, $(SORT_SRC)) \
	$(addprefix $(UTILS_DIR)/, $(UTILS_SRC)) \
	$(addprefix $(ERRORS_DIR)/, $(ERRORS_SRC))

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re