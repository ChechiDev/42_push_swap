/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:47:20 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/26 16:48:32 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	print_label(char *label)
{
	ft_putchar_fd('[', 2);
	while (*label)
	{
		ft_putchar_fd(*label, 2);
		label++;
	}
	ft_putchar_fd(']', 2);
}

void	print_stack(t_list *stack, char *label)
{
	print_label(label);
	while (stack)
	{
		ft_putchar_fd(' ', 2);
		ft_putnbr(stack->content, 2);
		stack = stack->next;
	}
	ft_putchar_fd('\n', 2);
}
