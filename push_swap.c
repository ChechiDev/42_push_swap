/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:50:46 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/24 13:00:40 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_options	*options;
	t_stacks	stack;

	options = NULL;
	stack_a = NULL;
	stack_b = NULL;
	stack.stack_a = &stack_a;
	stack.stack_b = &stack_b;
	if (!check_first(argc, argv, stack))
		return (0);
	parse_options(argc, argv, &options);
	return (0);
}
