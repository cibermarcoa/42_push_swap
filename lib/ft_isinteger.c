#include "libft.h"

int ft_isinteger(const char *str)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	sign = 1;
	n = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + (str[i] - '0');
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (0);
		i++;
	}
	while (ft_isspace(str[i]))
		i++;
	return (str[i] == '\0');
}