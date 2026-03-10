/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:44:31 by sperez-l          #+#    #+#             */
/*   Updated: 2026/03/10 14:44:37 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_complex(t_stacks stack, t_stats **bench)
{
	(*bench)->algorithm = COMPLEX;
	complex_algorithm(stack.stack_a, stack.stack_b, bench);
	bench_count(bench);
	bench_print_info(bench, COMPLEX);
}
