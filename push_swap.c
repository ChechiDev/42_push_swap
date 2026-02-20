/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:50:46 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/20 11:10:16 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_options	*options;
	t_stacks	s;

	(void)stack_a = NULL;
	(void)stack_b = NULL;
	(void)options = NULL;
	if (argc <= 1)
	{
		printf("Usage: %s --<flag> <Arg1> <Arg2> ... <ArgN>", argv[0]);
		return (0);
	}
	options = (t_options *)malloc(sizeof(t_options));
	if (!options)
		return (ft_putstr_fd("Error\n", 2), 1);
	return (0);
}
