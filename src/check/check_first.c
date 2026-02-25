/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:18:47 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/25 18:42:38 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_first(int argc, char **argv, t_stacks stack)
{
	if (argc == 1)
		return (0);
	if (!parse_params(argc, argv, stack.stack_a))
		return (0);
	return (1);
}
