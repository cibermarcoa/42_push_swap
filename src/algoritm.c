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













// int contains(t_stack *stack, long n)
// {
// 	int i;

// 	i = 0;
// 	while (i < stack->top)
// 	{
// 		if (stack->data[i] <= n)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// void	ft_sort_all_elements(t_stack *stack_a, t_stack *stack_b)
// {
// 	long n;
// 	int	i;

// 	i = 0;
// 	n = 0;
// 	while (i < stack_a->top)
// 	{
// 		n += stack_a->data[i];
// 		i++;
// 	}
// 	n /= 3;
// 	while (ft_is_empty(stack_a))
// 	{
// 		if (contains(stack_a, n))
// 			pb(stack_a, stack_b);
// 		else
// 			ra(stack_a);
// 	}
	

// }







// First version of the algo 1519 in 100n (must be <1500), for 500 32522 (must be <11500)
void	ft_sort_all_elements(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top > 2)
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
	ft_sort_three_elements(stack_a);
	while (stack_b->top > -1)
		pa(stack_a, stack_b);
}
