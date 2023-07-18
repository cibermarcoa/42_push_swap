# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRC_DIR := src
INC_DIR := inc
LIB_DIR := lib

# Files and directories
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
LIBS := $(wildcard $(LIB_DIR)/*.c)

# Executable
NAME := push_swap

# Makefile rules
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

-include $(DEPS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c | inc lib
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I $(INC_DIR) -I $(LIB_DIR)

lib:
	@mkdir -p $(LIB_DIR)

inc:
	@mkdir -p $(INC_DIR)

clean:
	$(RM) -r $(OBJS) $(DEPS)
	@rmdir $(LIB_DIR) $(INC_DIR) 2>/dev/null || true

fclean: clean
	$(RM) $(NAME)

re: fclean all
