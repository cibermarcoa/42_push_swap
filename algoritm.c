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

	while (stack_a->top > 2)
	{
		min = ft_find_min(stack_a);
		max = ft_find_max(stack_a);

		if (stack_a->data[0] == min)
			rra(stack_a);
		else if (stack_a->data[stack_a->top - 1] == min)
			sa(stack_a);
		else if (stack_a->data[stack_a->top] == min)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	ft_sort_three_elements(stack_a);
	while (!ft_is_empty(stack_b))
		pa(stack_a, stack_b);
}
/*
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

void ft_quick_sort(t_stack* stack_a, t_stack* stack_b, int size) {
	if (size <= 3) {
		ft_sort_three_elements(stack_a);
	} else if (size <= 5) {
		ft_sort_five_elements(stack_a, stack_b);
	} else {
		int pivot_index = size / 2;
		int pivot = stack_a->data[pivot_index];
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
}*/

t_stack	ft_merge(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		aux_stack;

	ft_init_stack(&aux_stack);
	/*while (stack_a->top != -1 && stack_b->top != -1)
	{
		if (stack_a->top <= stack_b->top)
			pa(stack_a, stack_b);
		else
			pb(stack_a, stack_b);
	}
	while (stack_a->top != -1)
		pb(stack_a, stack_b);
	while (stack_b->top != -1)
		pa(&aux_stack, stack_b);*/
	return (aux_stack);

}

t_stack		ft_sub(t_stack *stack, int first, int last)
{
	int			i;
	t_stack		aux_stack;

	ft_init_stack(&aux_stack);
	i = 0;
	while (first <= last)
	{
		aux_stack.data[i] = stack->data[first];
		i++;
		first++;
	}
	aux_stack.top = i - 1;
	return (aux_stack);
}

t_stack	ft_mergesort(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		aux_stack_a;
	t_stack		aux_stack_b;

	ft_init_stack(&aux_stack_a);
	ft_init_stack(&aux_stack_b);
	aux_stack_a = ft_sub(stack_a, 0, stack_a->top / 2);
printf("   %d\n", stack_a->top / 2);

	int i = 0;
	printf("\n");
	while (i <= aux_stack_a.top)
	{
		printf("%d ", aux_stack_a.data[i]);
		i++;
	}

printf("   %d\n", aux_stack_a.top);


	aux_stack_b = ft_sub(stack_a, (aux_stack_a.top + 1), stack_a->top);

	i = 0;
	printf("\n");
	while (i <= aux_stack_b.top)
	{
		printf("%d ", aux_stack_b.data[i]);
		i++;
	}

printf("   %d\n", aux_stack_b.top);

/*

	ft_mergesort(&aux_stack_a, stack_b);
	ft_mergesort(&aux_stack_b, stack_b);*/
	return (ft_merge(&aux_stack_a, &aux_stack_b));

}

/*
función mergesort(stack_a)
    si tamaño(stack_a) <= 1 entonces
        retornar stack_a

    mitad = tamaño(stack_a) / 2
    stack_izq = sub-stack(stack_a, 0, mitad)
    stack_der = sub-stack(stack_a, mitad, tamaño(stack_a))

    stack_izq = mergesort(stack_izq)
    stack_der = mergesort(stack_der)

    retornar merge(stack_izq, stack_der)


función merge(stack_a, stack_b)
    nuevo_stack = nuevo stack vacío

    mientras no está_vacío(stack_a) y no está_vacío(stack_b) hacer
        si tope(stack_a) <= tope(stack_b) entonces
            pa  // push a
        sino
            pb  // push b

    mientras no está_vacío(stack_a) hacer
        pa  // push a

    mientras no está_vacío(stack_b) hacer
        pb  // push b

    retornar nuevo_stack


procedimiento ordenar_mergesort(stack_a)
    stack_a = mergesort(stack_a)*/