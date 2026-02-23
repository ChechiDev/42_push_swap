/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:18:47 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/23 17:34:18 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_first(int argc, char argv, t_stacks stack)
{
	if (argc == 1)
	{
		write(1, "Error\n", 5);
		return (0);
	}
	else if (argc == 2)
	{
		if (!parse_options())
		{
		}
	}
}
