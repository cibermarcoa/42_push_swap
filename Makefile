# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Directories
LIB_DIR := lib
INC_DIR := $(LIB_DIR)
LIB_OBJ_DIR := $(LIB_DIR)/obj

# Files
LIB_SRCS := $(wildcard $(LIB_DIR)/*.c)
LIB_OBJS := $(LIB_SRCS:$(LIB_DIR)/%.c=$(LIB_OBJ_DIR)/%.o)
LIB_NAME := $(LIB_DIR)/libft.a

# push_swap files
PUSH_SWAP_DIR := src
PUSH_SWAP_OBJ_DIR := $(PUSH_SWAP_DIR)/obj
PUSH_SWAP_SRCS := $(wildcard $(PUSH_SWAP_DIR)/*.c)
PUSH_SWAP_OBJS := $(PUSH_SWAP_SRCS:$(PUSH_SWAP_DIR)/%.c=$(PUSH_SWAP_OBJ_DIR)/%.o)
PUSH_SWAP_NAME := push_swap

# Makefile rules
.PHONY: all clean fclean re

all: $(LIB_NAME) $(PUSH_SWAP_NAME)

$(LIB_NAME): $(LIB_OBJS)
	ar rcs $@ $^

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJS) $(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $^ -I $(INC_DIR)

$(LIB_OBJ_DIR)/%.o: $(LIB_DIR)/%.c | $(LIB_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(PUSH_SWAP_OBJ_DIR)/%.o: $(PUSH_SWAP_DIR)/%.c | $(PUSH_SWAP_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(LIB_OBJ_DIR):
	@mkdir -p $(LIB_OBJ_DIR)

$(PUSH_SWAP_OBJ_DIR):
	@mkdir -p $(PUSH_SWAP_OBJ_DIR)

clean:
	$(RM) -r $(LIB_OBJ_DIR)
	$(RM) -r $(PUSH_SWAP_OBJ_DIR)

fclean: clean
	$(RM) $(LIB_NAME) $(PUSH_SWAP_NAME)

re: fclean all
