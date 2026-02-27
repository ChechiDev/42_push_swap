/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:12:20 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/27 11:12:47 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_option(t_flag_opt *opt, t_stats *st, t_options *o)
{
	if (o->count == 2)
	{
		st->isbench = 1;
		if (o->options[0] != BENCH)
			*opt = o->options[0];
		else
			*opt = o->options[1];
	}
	else if (o->count == 1)
	{
		if (o->options[0] == BENCH)
		{
			st->isbench = 1;
			st->isadaptive = 1;
		}
		else
			*opt = o->options[0];
	}
	return (1);
}

