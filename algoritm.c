#include "push_swap.h"

void	ft_sort_three_elements(t_stack *stack_a)
{
	if (stack_a->data[stack_a->top] > stack_a->data[stack_a->top - 1])
		sa(stack_a);
	if (stack_a->data[stack_a->top - 1] > stack_a->data[stack_a->top - 2])
	{
		rra(stack_a);
		if (stack_a->data[stack_a->top] > stack_a->data[stack_a->top - 1])
			sa(stack_a);
	}
}

void	ft_sort_five_elements(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top > 2)
	{
		if (stack_a->data[0] == ft_find_min(stack_a))
			rra(stack_a);
		else if (stack_a->data[stack_a->top - 1] == ft_find_min(stack_a))
			sa(stack_a);
		else if (stack_a->data[stack_a->top] == ft_find_min(stack_a))
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	ft_sort_three_elements(stack_a);
	while (!ft_is_empty(stack_b))
		pa(stack_a, stack_b);
}

void	ft_sort_all_elements(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top > 4)
	{
		if (stack_a->data[stack_a->top] == ft_find_min(stack_a))
			pb(stack_a, stack_b);
		if (ft_is_close_to_top(stack_a, ft_find_min(stack_a)))
			while (stack_a->data[stack_a->top] != ft_find_min(stack_a))
				ra(stack_a);
		else
			while (stack_a->data[stack_a->top] != ft_find_min(stack_a))
				rra(stack_a);
	}
	ft_sort_five_elements(stack_a, stack_b);
	while (stack_b->top > -1)
		pa(stack_a, stack_b);
}
