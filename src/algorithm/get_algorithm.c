/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:15:27 by sperez-l          #+#    #+#             */
/*   Updated: 2026/03/02 17:38:56 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_algorithm(t_optype opt, t_stacks stack, t_stats **stats)
{
	if (opt == UNDEFINED || opt == ADAPTIVE)
	{
		(*stats)->isadaptive = 1;
		if ((*stats)->dis_index == 0)
			opt = UNDEFINED;
	}	
}
