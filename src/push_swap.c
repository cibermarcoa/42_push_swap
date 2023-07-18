#include "push_swap.h"

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


int	main(int argc, char **argv)
{
	int			i;
	t_stack		stack_a;
	t_stack		stack_b;

	if (argc < 2)
		exit(EXIT_FAILURE);
	valid_args(argc, argv);
	ft_init_stack(&stack_a);
	ft_init_stack(&stack_b);
	i = argc - 1;
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
