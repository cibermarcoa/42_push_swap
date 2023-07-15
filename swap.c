#include "push_swap.h"

int	ft_swap(t_stack *stack)
{
	int	aux;

	if (stack->top < 1)
		return (0);
	aux = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = aux;
	return (1);
}

void	sa(t_stack *stack_a)
{
	if (ft_swap(stack_a))
		ft_putendl_fd("sa", STDOUT_FILENO);
}

void	sb(t_stack *stack_b)
{
	if (ft_swap(stack_b))
		ft_putendl_fd("sb", STDOUT_FILENO);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_swap(stack_a) && ft_swap(stack_b))
		ft_putendl_fd("ss", STDOUT_FILENO);
}
