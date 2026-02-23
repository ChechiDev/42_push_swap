/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:46:15 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/23 17:48:10 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	add_node(char *argv, t_list **stack_a)
{
	t_list	*node;

	node = ft_lstnew(ft_atol(argv));
	if (!node)
		return (0);
	ft_lstadd_back(stack_a, node);
	return (1);
}
