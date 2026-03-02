/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:24:09 by sperez-l          #+#    #+#             */
/*   Updated: 2026/03/02 17:22:43 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_adaptive(t_stacks stack, t_options **options)
{
	t_optype	get_option;
	t_stats		*stats;

	get_option = UNDEFINED;
	stats = malloc(sizeof(t_stats));
	if (!stats)
		return ;
	ft_bzero(stats, sizeof(t_stats));
	stats->size_stack_a = ft_lstsize(*stack.stack_a);
	stats->dis_index = parse_disorder_index(stats->size_a, *stack.stack_a);
	if (*options)
		get_option(&get_option, stats, *options); 
	get_algorithm(get_option, stack, &stats);
	free(stats);
}
