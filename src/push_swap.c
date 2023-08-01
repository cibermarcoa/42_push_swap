#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_stack		stack_a;
	t_stack		stack_b;

	if (argc < 2)
		ft_error();
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
	// i = 0;
	// printf("Stack a:");
	// while (i < stack_a.top + 1)
	// {
	// 	printf("%d ", stack_a.data[i]);
	// 	i++;
	// }
	// printf("\n");
	// i = 0;
	// printf("Stack b:");
	// while (i < stack_b.top + 1)
	// {
	// 	printf("%d ", stack_b.data[i]);
	// 	i++;
	// }
	// printf("\n");
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
