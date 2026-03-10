/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:15:27 by sperez-l          #+#    #+#             */
/*   Updated: 2026/03/10 13:54:51 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_simple(t_stacks stack, t_stats **stats)
{
	if ((*stats)->isbench)
		bench_simple(stack, stats);
	else
		simple(stack.stack_a, stack.stack_b, NULL);
}

static void	set_medium(t_stacks stack, t_stats **stats)
{
	if ((*stats)->isbench)
		bench_medium(stack, stats);
	else
		medium(stack, NULL);
}

static void	set_complex(t_stacks stack, t_stats **stats)
{
	if ((*stats)->isbench)
		bench_complex(stack, stats);
	else
		complex_algorithm(stack.stack_a, stack.stack_b, NULL);
}

void	get_algorithm(t_flag_opt opt, t_stacks stack, t_stats **stats)
{
	if (opt == UNDEFINED || opt == ADAPTIVE)
	{
		(*stats)->isadaptive = 1;
		if ((*stats)->dis_index == 0)
			opt = UNDEFINED;
		else if ((*stats)->dis_index < 20)
			opt = SIMPLE;
		else if ((*stats)->dis_index < 50)
			opt = MEDIUM;
		else if ((*stats)->dis_index >= 50)
			opt = COMPLEX;
	}
	if (opt == SIMPLE)
		set_simple(stack, stats);
	else if (opt == MEDIUM)
		set_medium(stack, stats);
	else if (opt == COMPLEX)
		set_complex(stack, stats);
	else if ((*stats)->isbench)
		bench_print_info(stats, SIMPLE);
}
