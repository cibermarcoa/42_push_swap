#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <unistd.h>

// Conversion
int ft_atoi(const char *str);
int ft_isinteger(const char *str);

// Character checks
int ft_isdigit(int c);
int ft_isspace(char c);

// Output
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);

// String
size_t ft_strlen(const char *s);
int ft_strcmp(char *s1, char *s2);

#endif

