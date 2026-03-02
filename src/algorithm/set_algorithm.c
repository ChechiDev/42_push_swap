/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:24:09 by sperez-l          #+#    #+#             */
/*   Updated: 2026/03/02 16:52:28 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void	set_adaptive(t_stacks stack, t_options **options)
{
	t_optype	get_option;
	t_stats		*stats;

	get_option = UNDEFINED;
	stats = malloc(sizeof(t_stats 1));
	if (!stats)
		return ;
	if (*options)
		get_option(&get_option, stats, *options); 
	get_algorithm(get_option, stack, stats);
	free(stats);
}
