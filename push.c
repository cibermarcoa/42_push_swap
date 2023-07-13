#include "push_swap.h"

void	ft_push(t_stack *stack, int value)
{
	if (stack->top == MAX_STACK_SIZE - 1)
	{
		fprintf(stderr, "Error: Stack overflow\n");
		exit(1);
	}
	stack->data[++stack->top] = value;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_is_empty(stack_b))
	{
		ft_push(stack_a, ft_pop(stack_b));
		printf("pa\n");
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_is_empty(stack_a))
	{
		ft_push(stack_b, ft_pop(stack_a));
		printf("pb\n");
	}
}
