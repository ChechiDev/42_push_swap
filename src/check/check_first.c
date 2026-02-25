/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:18:47 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/24 17:21:17 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_first(int argc, char **argv, t_stacks stack)
{
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (!parse_params(argc, argv, stack.stack_a))
			return (0);
	}
	return (1);
}
