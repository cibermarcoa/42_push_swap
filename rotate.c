#include "push_swap.h"

void	ft_rotate(t_stack *stack)
{
	int		i;
	int		aux;

	if (stack->top >= 1)
	{
		i = stack->top;
		aux = stack->data[stack->top];
		while (i > 0)
		{
			stack->data[i] = stack->data[i - 1];
			--i;
		}
		stack->data[0] = aux;
	}
}

void	ra(t_stack *stack_a)
{
	ft_rotate(stack_a);
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	rb(t_stack *stack_b)
{
	ft_rotate(stack_b);
	ft_putendl_fd("rb", STDOUT_FILENO);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putendl_fd("rr", STDOUT_FILENO);
}
