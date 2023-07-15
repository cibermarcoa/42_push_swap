#include "push_swap.h"

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


void ft_init_stack(t_stack * stack)
{
	stack->top = -1;
}

int	ft_is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

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

int	ft_find_min(t_stack *stack)
{
	int min = stack->data[stack->top];
	for (int i = stack->top - 1; i >= 0; --i) {
		if (stack->data[i] < min) {
			min = stack->data[i];
		}
	}
	return min;
}

int ft_find_max(t_stack * stack) {
	int max = stack->data[stack->top];
	for (int i = stack->top - 1; i >= 0; --i) {
		if (stack->data[i] > max) {
			max = stack->data[i];
		}
	}
	return max;
}

int	ft_pop(t_stack *stack)
{
	if (ft_is_empty(stack))
	{
		fprintf(stderr, "Error: Stack underflow\n");
		exit(1);
	}
	return (stack->data[stack->top--]);
}

int	ft_peek(t_stack *stack)
{
	if (ft_is_empty(stack))
	{
		fprintf(stderr, "Error: Stack is empty\n");
		exit(1);
	}
	return (stack->data[stack->top]);
}
