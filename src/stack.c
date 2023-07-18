#include "push_swap.h"

void	ft_init_stack(t_stack *stack)
{
	stack->top = -1;
}

int	ft_is_empty(t_stack *stack)
{
	return (stack->top == -1);
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
