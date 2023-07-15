#include "push_swap.h"

void	ft_reverse_rotate(t_stack *stack)
{
	int		i;
	int		aux;

	if (stack->top >= 1)
	{
		i = 0;
		aux = stack->data[0];
		while (i < stack->top)
		{
			stack->data[i] = stack->data[i + 1];
			i++;
		}
		stack->data[stack->top] = aux;
	}
}

void	rra(t_stack *stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_putendl_fd("rra", STDOUT_FILENO);
}

void	rrb(t_stack *stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_putendl_fd("rrb", STDOUT_FILENO);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_putendl_fd("rrr", STDOUT_FILENO);
}
