/*
pa (push a):
Toma el primer elemento del stack b y lo coloca el primero en el stack a.
No hace nada si b está vacío.

pb (push b):
Toma el primer elemento del stack a y lo coloca el primero en el stack b.

No hace nada si a está vacío.
*/

#include "libft.h"
#include "push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write (1, "pb\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write (1, "pa\n", 3);
}
