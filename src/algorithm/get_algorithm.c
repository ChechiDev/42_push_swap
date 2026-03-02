/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:15:27 by sperez-l          #+#    #+#             */
/*   Updated: 2026/03/02 18:19:48 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_algorithm(t_flag_opt opt, t_stacks stack, t_stats **stats)
{
	if (opt == UNDEFINED || opt == ADAPTIVE)
	{
		(*stats)->isadaptive = 1;
		if ((*stats)->dis_index == 0)
			opt = UNDEFINED;
		else if ((*stats)->dis_index < 20)
			opt = SIMPLE;
	}	
}
