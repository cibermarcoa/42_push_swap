#include "push_swap.h"

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
		*stack_a = ft_mergesort(stack_a, stack_b);
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
	while (i > 0)
	{
		ft_push(&stack_a, atoi(argv[i]));
		i--;
	}
	ft_push_swap(&stack_a, &stack_b);
	i = 0;
	printf("\n");
	while (i <= stack_a.top)
	{
		printf("%d ", stack_a.data[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i <= stack_b.top)
	{
		//printf("%d ", stack_b.data[i]);
		i++;
	}
	return (0);
}
