/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javisan2 <javisan2@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:33:46 by javisan2          #+#    #+#             */
/*   Updated: 2026/03/04 17:33:48 by javisan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
sa (swap a):
Intercambia los dos primeros elementos del stack a.
No hace nada si hay solo uno o ningún elemento.

sb (swap b):
Intercambia los dos primeros elementos del stack b.
No hace nada si hay solo uno o ningún elemento.

ss :saysbalavez.
*/

#include "libft.h"
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

static void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	if (!stack_a || !*stack_a)
		return ;
	ft_write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	if (!stack_b || !*stack_b)
		return ;
	ft_write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_write(1, "ss\n", 3);
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
