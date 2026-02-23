/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:36:49 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/23 18:37:06 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_params(int argc, char **argv, t_list **stack_a)
{
	int			i;
	int			count;
	t_flags		flags;

	flags = (t_flags){0};
	*stack_a = NULL;
	i = (check_flags(argc, argv, flags));
	if (i == -1 || i > 3)
		return (write(2, "Error\n", 6), 0);
	if (!check_num(argv + i) || !check_minmax(argv + i))
		return (write(2, "Error\n", 6), 0);
	count = 0;
	while (i < argc)
	{
		if (!add_node(argv[i], stack_a))
			return (write(2, "Error\n", 6), 0);
		count++;
		i++;
	}
	if (count > 0)
		parse_disorder_index(count, *stack_a);
	return (1);
}
