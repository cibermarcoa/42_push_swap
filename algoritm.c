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
	int		min;
	int		max;

	while (stack_a->top >= 2)
	{
		min = ft_find_min(stack_a);
		max = ft_find_max(stack_a);
		if (stack_a->data[stack_a->top] == max
			|| stack_a->data[stack_a->top] == min)
			ra(stack_a);
		else if (stack_a->data[stack_a->top - 1] == max
			|| stack_a->data[stack_a->top - 1] == min)
			rra(stack_a);
		else
			pb(stack_a, stack_b);
	}
	ft_sort_three_elements(stack_a);
	while (!ft_is_empty(stack_b))
		pa(stack_a, stack_b);
}

void ft_quick_sort(t_stack *stack_a, t_stack *stack_b, int size) {
	if (size <= 3) {
		ft_sort_three_elements(stack_a);
	} else if (size <= 5) {
		ft_sort_five_elements(stack_a, stack_b);
	} else {
		int pivot = stack_a->data[stack_a->top];
		t_stack smaller, greater;
		ft_init_stack(&smaller);
		ft_init_stack(&greater);

		while (!ft_is_empty(stack_a)) {
			int value = ft_pop(stack_a);
			if (value < pivot) {
				ft_push(&smaller, value);
			} else {
				ft_push(&greater, value);
			}
		}

		ft_quick_sort(&smaller, stack_b, smaller.top + 1);
		ft_quick_sort(&greater, stack_b, greater.top + 1);

		while (!ft_is_empty(&greater)) {
			ft_push(stack_a, ft_pop(&greater));
		}
		ft_push(stack_a, pivot);
		while (!ft_is_empty(&smaller)) {
			ft_push(stack_a, ft_pop(&smaller));
		}
	}
}