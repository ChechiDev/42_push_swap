#include "push_swap.h"
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%d -> ", head->value);
		head = head->next;
	}
	printf("NULL\n");
}

t_list	*new_node(int value)
{
	t_list	*node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}
*/

void	sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write (1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	write (1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write (1, "ss\n", 3);
}

/*
int	main(void)
{
	t_list	*a = new_node(3);
	a->next = new_node(2);
	a->next->next = new_node(1);

	printf("Before:\n");
	print_list(a);

	sb(&a);

	printf("After:\n");
	print_list(a);

	return (0);
}
*/
