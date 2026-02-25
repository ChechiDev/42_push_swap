//#include "push_swap.h"

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



void	rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "rra\n", 4);
}


int	main(void)
{
	t_list	*a = new_node(3);
	a->next = new_node(2);
	a->next->next = new_node(1);

	printf("Before:\n");
	print_list(a);

	rra(&a);

	printf("After:\n");
	print_list(a);

	return (0);
}

