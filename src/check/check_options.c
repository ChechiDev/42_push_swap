/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:59:00 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/23 16:05:09 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_options(t_options **options)
{
	int	i;
	int	algo_count;

	i = 0;
	algo_count = 0;
	while (i < (*options)->count)
	{
		if ((*options)->options[i] != BENCH)
			algo_count++;
		i++;
	}
	if (algo_count > 1)
	{
		return (0);
	}
	return (1);
}
