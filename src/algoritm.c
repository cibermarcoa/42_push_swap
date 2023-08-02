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
		if (stack_a->data[stack_a->top] == ft_find_min(stack_a))
			pb(stack_a, stack_b);
		else if (stack_a->data[stack_a->top - 1] == ft_find_min(stack_a)
			|| stack_a->data[stack_a->top - 2] == ft_find_min(stack_a))
			ra(stack_a);
		else
			rra(stack_a);
	}
	ft_sort_three_elements(stack_a);
	while (!ft_is_empty(stack_b))
		pa(stack_a, stack_b);
}

long	average(t_stack *stack)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	while (i <= stack->top)
	{
		n += stack->data[i];
		i++;
	}
	n /= (stack->top + 1);
	return (n);
}

void	ft_sort_all_elements_aux(t_stack *stack_a, t_stack *stack_b)
{
	while (!ft_is_empty(stack_b))
	{
		if (stack_b->data[stack_b->top] == ft_find_max(stack_b))
			pa(stack_a, stack_b);
		else
		{
			if (ft_is_close_to_top(stack_b, ft_find_max(stack_b)))
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
}

void	ft_sort_all_elements(t_stack *stack_a, t_stack *stack_b)
{
	long		limit;

	limit = average(stack_a);
	while (!ft_is_empty(stack_a))
	{
		if (contains_below(stack_a, limit))
		{
			if (stack_a->data[stack_a->top] <= limit)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		else
			limit = average(stack_a);
	}
	ft_sort_all_elements_aux(stack_a, stack_b);
}
