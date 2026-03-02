/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:24:09 by sperez-l          #+#    #+#             */
/*   Updated: 2026/03/02 17:50:09 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_adaptive(t_stacks stack, t_options **options)
{
	t_flag_opt	opt;
	t_stats		*stats;

	opt = UNDEFINED;
	stats = malloc(sizeof(t_stats));
	if (!stats)
		return ;
	ft_bzero(stats, sizeof(t_stats));
	stats->size_a = ft_lstsize(*stack.stack_a);
	stats->dis_index = parse_disorder_index(stats->size_a, *stack.stack_a);
	if (options && *options)
		get_option(&opt, stats, *options); 
	else
		stats->isadaptive = 1;
	get_algorithm(opt, stack, &stats);
	free(stats);
}
