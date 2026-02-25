#include "push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*runner;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	runner = *stack_a;
	while (runner->next != NULL)
	{
		last = runner;
		runner = runner->next;
	}
	last->next = NULL;
	runner->next = *stack_a;
	*stack_a = runner;
	write (1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*runner;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	runner = *stack_b;
	while (runner->next)
	{
		last = runner;
		runner = runner->next;
	}
	last->next = NULL;
	runner->next = *stack_b;
	*stack_b = runner;
	write (1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write (1, "rrr\n", 4);
}
