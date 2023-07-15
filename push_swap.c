#include "push_swap.h"

void ft_quicksort(t_stack* stack_a, t_stack* stack_b)
{
    while (stack_a->top > 3)
	{
        int min = ft_find_min(stack_a);
        int max = ft_find_max(stack_a);

        while (stack_a->data[stack_a->top] != min && stack_a->data[stack_a->top] != max) {
            pb(stack_a, stack_b);
        }

        if (stack_a->data[stack_a->top] == max) {
            ra(stack_a);
        }
    }

    ft_sort_three_elements(stack_a);

    while (stack_b->top > 0) {
        pa(stack_a, stack_b);
    }
}

void sortRemaining(Stack* stack) {
    int raCount = 0;
    int rraCount = 0;

    Node* current = stack->top;

    while (current->next != stack->top) {
        current = current->next;
        raCount++;
    }

    current = stack->top;

    while (current->prev != stack->top) {
        current = current->prev;
        rraCount++;
    }

    if (raCount < rraCount) {
        for (int i = 0; i < raCount; i++) {
            rotate(stack);
        }
    } else {
        for (int i = 0; i < rraCount; i++) {
            reverseRotate(stack);
        }
    }
}

void	ft_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_is_sorted(stack_a))
		return ;
	if (stack_a->top == 1)
		sa(stack_a);
	else if (stack_a->top == 2)
		ft_sort_three_elements(stack_a);
	else if (stack_a->top <= 4)
		ft_sort_five_elements(stack_a, stack_b);
	else
		ft_quicksort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	int			i;
	t_stack		stack_a;
	t_stack		stack_b;

	if (argc < 2)
		return (0);
	ft_init_stack(&stack_a);
	ft_init_stack(&stack_b);
	i = argc - 1;
	while (i > 0)
	{
		ft_push(&stack_a, atoi(argv[i]));
		i--;
	}
	ft_push_swap(&stack_a, &stack_b);
	i = 0;
	printf("\n");
	while (i <= stack_a.top)
	{
		printf("%d ", stack_a.data[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i <= stack_b.top)
	{
		//printf("%d ", stack_b.data[i]);
		i++;
	}
	return (0);
}
