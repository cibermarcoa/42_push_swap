#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->data[i] < stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_max(t_stack *stack)
{
	int		i;
	int		max;

	i = stack->top - 1;
	max = stack->data[stack->top];
	while (i >= 0)
	{
		if (stack->data[i] > max)
			max = stack->data[i];
		i--;
	}
	return (max);
}

int	ft_find_min(t_stack *stack)
{
	int		i;
	int		min;

	i = stack->top - 1;
	min = stack->data[stack->top];

	while (i >= 0)
	{
		if (stack->data[i] < min)
			min = stack->data[i];
		i--;
	}
	return (min);
}

int	ft_is_close_to_top(t_stack *stack, int data)
{
	int		i;

	i = stack->top;
	while (i > (stack->top / 2))
	{
		if (stack->data[i] == data)
			return (1);
		i--;
	}
	return (0);
}
