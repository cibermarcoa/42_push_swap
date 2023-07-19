# Compiler and flags
CC := clang
CFLAGS := -Wall -Wextra -Werror

# Directories
SRC_DIR := .
OBJ_DIR := obj
INC_DIR := .

# Files
SRCS := ft_atoi.c ft_isinteger.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c \
        ft_isdigit.c ft_isspace.c ft_putendl_fd.c ft_strcmp.c
OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)
LIB_NAME := libft.a

# Makefile rules
.PHONY: all clean fclean re

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	ar rcs $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | obj
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

obj:
	@mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(LIB_NAME)

re: fclean all
