/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:18:47 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/24 11:56:20 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_first(int argc, char **argv, t_stacks stack)
{
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (!parse_options(argc, argv, stack.stack_a))
			return (0);
	}
	return (1);
}
