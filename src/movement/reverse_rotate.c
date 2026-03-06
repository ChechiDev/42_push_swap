/*
rra (reverse rotate a):
Desplaza hacia abajo todos los elementos del stack a una
posición, convirtiendo el último elemento en el primero.

rrb (reverse rotate b):
Desplaza hacia abajo todos los elementos del stack b una
posición, convirtiendo el último elemento en el primero.

rrr :rrayrrbalavez.
*/

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*runner;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	runner = *stack;
	while (runner->next != NULL)
	{
		last = runner;
		runner = runner->next;
	}
	last->next = NULL;
	runner->next = *stack;
	*stack = runner;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	if (!stack_a || !*stack_a)
		return ;
	ft_write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	if (!stack_b || !*stack_b)
		return ;
	ft_write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_write(1, "rrr\n", 4);
}
