/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javisan2 <javisan2@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:33:05 by javisan2          #+#    #+#             */
/*   Updated: 2026/03/10 12:12:00 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	pb(t_list **stack_a, t_list **stack_b, t_stats **bench)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	ft_write(1, "pb\n", 3);
	if (bench && *bench)
		(*bench)->pb_count++;
}

void	pa(t_list **stack_a, t_list **stack_b, t_stats **bench)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	ft_write(1, "pa\n", 3);
	if (bench && *bench)
		(*bench)->pa_count++;
}
