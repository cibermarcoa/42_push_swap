#include "push_swap.h"

int ft_isinteger(char *element)
{
    long n = 0;
    int sign = 1;
    int i = 0;

    while (ft_isspace(element[i]))
        i++;
    if (element[i] == '-' || element[i] == '+') {
        if (element[i] == '-')
            sign = -1;
        i++;
    }

    // Procesamos los dígitos y construimos el número
    while (ft_isdigit(element[i]))
	{
        n = (n * 10) + (element[i] - '0');
        if (n * sign > INT_MAX || n * sign < INT_MIN)
            return 0;
        i++;
    }

    // Verificamos que no haya más caracteres después del número (excepto espacios en blanco)
    while (ft_isspace(element[i]))
        i++;
    return (element[i] == '\0');
}


int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 - *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	are_duplicated(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc < 2)
		exit(EXIT_SUCCESS);
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
	are_duplicated(argc, argv);
}

int	main(int argc, char **argv)
{
	int			i;
	t_stack		stack_a;
	t_stack		stack_b;

	if (argc < 2)
		return (0);
	ft_init_stack(&stack_a);
	ft_init_stack(&stack_b);
	i = argc - 1;
	valid_args(argc, argv);
	while (i > 0)
	{
		ft_push(&stack_a, ft_atoi(argv[i]));
		i--;
	}
	ft_push_swap(&stack_a, &stack_b);
	i = 0;
	while (i < stack_a.top + 2)
	{
		//printf("%d ", stack_a.data[i]);
		i++;
	}
	
	return (0);
}

void	ft_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_is_sorted(stack_a))
		return ;
	if (stack_a->top == 1)
		sa(stack_a);
	else if (stack_a->top == 2)
		ft_sort_three_elements(stack_a);
	else if (stack_a->top <= 4)
		ft_sort_five_elements(stack_a, stack_b);
	else
		ft_sort_all_elements(stack_a, stack_b);
}
