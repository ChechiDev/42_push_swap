/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javisan2 <javisan2@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:33:30 by javisan2          #+#    #+#             */
/*   Updated: 2026/03/10 11:42:14 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ra (rotate a): Desplaza hacia arriba todos los elementos del stack
a una posición, convirtiendo el primer elemento en el último.

rb (rotate b): Desplaza hacia arriba todos los elementos del stack
b una posición, convirtiendo el primer elemento en el último.

rr :ra y rb a la vez.
*/

#include "libft.h"
#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = ft_lstlast(*stack);
	last->next = first;
}

void	ra(t_list **stack_a, t_stats **bench)
{
	rotate(stack_a);
	if (!stack_a || !*stack_a)
		return ;
	ft_write(1, "ra\n", 3);
	if (bench && *bench)
		(*bench)->ra_count++;
}

void	rb(t_list **stack_b, t_stats **bench)
{
	rotate(stack_b);
	if (!stack_b || !*stack_b)
		return ;
	ft_write(1, "rb\n", 3);
	if (bench && *bench)
		(*bench)->rb_count++;
}

void	rr(t_list **stack_a, t_list **stack_b, t_stats **bench)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_write(1, "rr\n", 3);
	if (bench && *bench)
		(*bench)->rr_count++;
}
