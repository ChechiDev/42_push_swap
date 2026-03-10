/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:11:06 by sperez-l          #+#    #+#             */
/*   Updated: 2026/03/10 12:08:55 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_simple(t_stacks stack, t_stats **bench)
{
	(*bench)->algorithm = SIMPLE;
	simple(stack.stack_a, stack.stack_b, bench);
	bench_count(bench);
	bench_print_info(bench, SIMPLE);
}
