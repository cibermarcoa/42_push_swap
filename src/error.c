#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	are_duplicated(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc < 2)
		return ;
	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (!ft_strcmp(argv[i], argv[j]) && i != j)
				exit(EXIT_FAILURE);
			j++;
		}
		i++;
	}
}

void	valid_args(int argc, char **argv)
{
	int	i;

	are_duplicated(argc, argv);
	i = 1;
	while (i < argc)
	{
		if (!ft_isinteger(argv[i]) || !ft_strlen(argv[i]))
			exit(EXIT_FAILURE);
		i++;
	}
	if (argc < 3)
		exit(EXIT_SUCCESS);
}
