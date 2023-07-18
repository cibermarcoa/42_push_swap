#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define MAX_STACK_SIZE 5000

typedef struct s_stack
{
	int	data[MAX_STACK_SIZE];
	int	top;
}		t_stack;

void	ft_push_swap(t_stack *stack_a, t_stack *stack_b);

void	ft_sort_three_elements(t_stack *stack_a);
void	ft_sort_five_elements(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_all_elements(t_stack *stack_a, t_stack *stack_b);

void	ft_push(t_stack *stack, int value);
int	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

int	ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);

void	ft_init_stack(t_stack *stack);
int	ft_is_empty(t_stack *stack);
int	ft_pop(t_stack *stack);

int	ft_is_sorted(t_stack *stack);
int	ft_find_min(t_stack *stack);
int	ft_find_max(t_stack *stack);
int	ft_is_close_to_top(t_stack *stack, int data);


int	ft_isspace(char c);
int	ft_isdigit(int c);
int ft_isinteger(char *str);
int	ft_strcmp(char *s1, char *s2);
void	ft_error(void);
void	valid_args(int argc, char **argv);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

#endif