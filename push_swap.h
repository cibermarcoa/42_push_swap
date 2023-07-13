#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>

# define MAX_STACK_SIZE 1000

typedef struct s_stack
{
    int data[MAX_STACK_SIZE];
    int top;
}       t_stack;

int ft_swap(t_stack *stack);
void ft_rotate(t_stack * stack);
void  ft_reverse_rotate(t_stack *stack);
void ft_push_to_other_stack(t_stack * src, t_stack * dest);

int ft_pop(t_stack *stack);
void ft_sort_three_elements(t_stack *stack_a);
void ft_sort_five_elements(t_stack *stack_a, t_stack *stack_b);

void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_a, t_stack *stack_b);
void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);
void rra(t_stack *stack_a);
void rrb(t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);

void ft_sort_two_elements(t_stack *stack_a);
void ft_sort_three_elements(t_stack *stack_a);
void ft_sort_five_elements(t_stack *stack_a, t_stack *stack_b);
void ft_quick_sort(t_stack *stack_a, t_stack *stack_b, int size);

void ft_init_stack(t_stack * stack);
int ft_is_empty(t_stack * stack);
void ft_push(t_stack * stack, int value);
int ft_pop(t_stack * stack);
int ft_peek(t_stack * stack);
void ft_rotate(t_stack * stack);
void  ft_reverse_rotate(t_stack * stack);
int ft_is_sorted(t_stack * stack);
int ft_find_min(t_stack * stack);
int ft_find_max(t_stack * stack);
void ft_push_swap(t_stack *stack_a, t_stack *stack_b);

#endif