/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:42:43 by sperez-l          #+#    #+#             */
/*   Updated: 2026/03/10 14:46:05 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_medium(t_stacks stack, t_stats **bench)
{
	(*bench)->algorithm = MEDIUM;
	medium(stack, bench);
	bench_count(bench);
	bench_print_info(bench, MEDIUM);
}
