#ifndef LIBFT_H
# define LIBFT_H
# include <limits.h>
# include <unistd.h>

int		ft_atoi(const char *str);
int		ft_isinteger(const char *str);

int		ft_isdigit(int c);
int		ft_isspace(char c);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);

#endif
