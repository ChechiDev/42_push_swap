/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:12:20 by sperez-l          #+#    #+#             */
/*   Updated: 2026/03/10 15:38:49 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_option(t_flag_opt *opt, t_stats *stats, t_options *o)
{
	if (o->count == 2)
	{
		stats->isbench = 1;
		if (o->options[0] != BENCH)
			*opt = o->options[0];
		else
			*opt = o->options[1];
	}
	else if (o->count == 1)
	{
		if (o->options[0] == BENCH)
		{
			stats->isbench = 1;
			stats->isadaptive = 1;
		}
		else
			*opt = o->options[0];
	}
	return (1);
}
