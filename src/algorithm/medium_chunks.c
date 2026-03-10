/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javisan2 <javisan2@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:32:03 by javisan2          #+#    #+#             */
/*   Updated: 2026/03/10 12:26:28 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_n_chunks(int n)
{
	if (n <= 5)
		return (1);
	else if (n <= 50)
		return (2);
	else if (n <= 100)
		return (6);
	else if (n <= 500)
		return (9);
	return (11);
}

int	in_range(t_list *stack_a, long *arr, int start, int end)
{
	while (stack_a)
	{
		if (stack_a->content >= arr[start] && stack_a->content <= arr[end])
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	get_top_pos(t_list *stack_a, long *arr, int start, int end)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->content >= arr[start] && stack_a->content <= arr[end])
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (-1);
}

void	nearest_number(t_stacks s, long *arr, t_stats **bench)
{
	int	top;
	int	bottom;
	int	size;
	int	pivot;

	top = get_top_pos(*s.stack_a, arr, s.start, s.end);
	bottom = get_bottom_pos(*s.stack_a, arr, s.start, s.end);
	size = ft_lstsize(*s.stack_a);
	if (top <= size - bottom)
	{
		while (top-- > 0)
			ra(s.stack_a, bench);
	}
	else
	{
		bottom = size - bottom;
		while (bottom-- > 0)
			rra(s.stack_a, bench);
	}
	pb(s.stack_a, s.stack_b);
	pivot = s.start + (s.end - s.start) / 2;
	if (ft_lstsize(*s.stack_b) > 1 && (*s.stack_b)->content < arr[pivot])
		rb(s.stack_b, bench);
}

void	get_chunks(t_stacks s, long *arr, t_stats **bench)
{
	int	total_size;
	int	chunks;
	int	size;
	int	i;

	total_size = ft_lstsize(*s.stack_a);
	chunks = get_n_chunks(total_size);
	size = total_size / chunks;
	i = 0;
	while (i < chunks)
	{
		s.start = i * size;
		if (i == chunks - 1)
			s.end = total_size - 1;
		else
			s.end = s.start + size -1;
		while (in_range(*s.stack_a, arr, s.start, s.end))
			nearest_number(s, arr, bench);
		i++;
	}
}
