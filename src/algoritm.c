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
		if (stack_a->data[stack_a->top - 1] == ft_find_min(stack_a) || stack_a->data[stack_a->top - 1] == ft_find_min(stack_a))
			ra(stack_a);
		else
			rra(stack_a);
	}
	ft_sort_three_elements(stack_a);
	while (!ft_is_empty(stack_b))
		pa(stack_a, stack_b);
}


int	average(t_stack *stack)
{
	long n;
	int	i;

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

int contains_below(t_stack *stack, int n)
{
	int i;

	i = 0;
	while (i <= stack->top)
	{
		if (stack->data[i] <= n)
			return (1);
		i++;
	}
	return (0);
}

void	ft_sort_all_elements(t_stack *stack_a, t_stack *stack_b)
{
	int		limit;

	limit = average(stack_a);
	//printf("Avrage is: %d\n", limit);
	limit /= 2;
	//printf("Limit is: %d\n", limit);
// !ft_is_empty(stack_a)
	while (!ft_is_empty(stack_a))
	{
		if (contains_below(stack_a, limit))
		{
			//printf("entra");
			if (stack_a->data[stack_a->top] <= limit)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		else
		{
			//limit = average(stack_a) / 2;
			limit *= 2;
			printf("LIMIT NOW IS: %d\n", limit);
		}
	}
	while (!ft_is_empty(stack_b))
	{
		if (stack_b->data[stack_b->top] == ft_find_max(stack_b))
		{
			pa(stack_a, stack_b);
		}
		else
		{
			if (ft_is_close_to_top(stack_b, ft_find_max(stack_b)))
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}

}







// First version of the algo 1519 in 100n (must be <1500), for 500 32522 (must be <11500)
// void	ft_sort_all_elements(t_stack *stack_a, t_stack *stack_b)
// {
// 	while (stack_a->top > 2)
// 	{
// 		if (stack_a->data[stack_a->top] == ft_find_min(stack_a))
// 			pb(stack_a, stack_b);
// 		if (ft_is_close_to_top(stack_a, ft_find_min(stack_a)))
// 			while (stack_a->data[stack_a->top] != ft_find_min(stack_a))
// 				ra(stack_a);
// 		else
// 			while (stack_a->data[stack_a->top] != ft_find_min(stack_a))
// 				rra(stack_a);
// 	}
// 	ft_sort_three_elements(stack_a);
// 	while (stack_b->top > -1)
// 		pa(stack_a, stack_b);
// }
