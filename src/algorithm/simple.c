/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javisan2 <javisan2@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:58:39 by javisan2          #+#    #+#             */
/*   Updated: 2026/03/04 16:58:42 by javisan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Algoritmo simple (O(n2)):
Implementa al menos un algoritmo base perteneciente a la clase de
complejidad O(n2).
• Métodos simples de extracción del mínimo/máximo
*/

#include "push_swap.h"

int	get_min(t_list *stack_a)
{
	int	min;
	int	index_min;
	int	index;

	if (!stack_a)
		return (0);
	min = stack_a->content;
	index_min = 0;
	index = 0;
	while (stack_a)
	{
		if (stack_a->content < min)
		{
			min = stack_a->content;
			index_min = index;
		}
		index++;
		stack_a = stack_a->next;
	}
	return (index_min);
}

void	sort_3(t_list **stack_a)
{
	int	node_1;
	int	node_2;
	int	node_3;

	node_1 = (*stack_a)->content;
	node_2 = (*stack_a)->next->content;
	node_3 = (*stack_a)->next->next->content;
	if (node_1 > node_2 && node_2 > node_3)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (node_2 > node_3 && node_1 < node_3)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (node_3 < node_2 && node_1 < node_2)
		rra(stack_a);
	else if (node_1 > node_2 && node_1 < node_3)
		sa(stack_a);
	else if (node_1 > node_2 && node_2 < node_3)
		ra(stack_a);
}

void	last_three(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else
		sort_3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	simple(t_list **stack_a, t_list **stack_b)
{
	int	nodes_a;
	int	pos_min_a;
	int	moves;

	if (!stack_a || !*stack_a || disorder_meter(*stack_a) == 0)
		return ;
	while (ft_lstsize(*stack_a) > 3)
	{
		nodes_a = ft_lstsize(*stack_a);
		pos_min_a = get_min(*stack_a);
		if (pos_min_a <= (nodes_a / 2))
		{
			while (pos_min_a-- != 0)
				ra(stack_a);
		}
		else
		{
			moves = nodes_a - pos_min_a;
			while (moves-- != 0)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	last_three(stack_a, stack_b);
}
