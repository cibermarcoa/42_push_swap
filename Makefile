NAME = push_swap

SRCS = ft_isspace.c algoritm.c error.c ft_atoi.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_strlen.c push.c push_swap.c rotate.c rotate_rev.c stack.c swap.c utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
