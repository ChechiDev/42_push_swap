/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:11:44 by sperez-l          #+#    #+#             */
/*   Updated: 2026/03/03 15:13:54 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_count(t_stats **stats)
{
	size_t	total;

	total = ((*stats)->ra_count + (*stats)->rb_count + (*stats)->rr_count
			+ (*stats)->rra_count + (*stats)->rrb_count + (*stats)->rrr_count
			+ (*stats)->pa_count + (*stats)->pb_count + (*stats)->sa_count
			+ (*stats)->sb_count + (*stats)->ss_count);
	(*stats)->total_count = total;
}
