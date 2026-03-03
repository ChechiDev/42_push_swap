/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_disorder_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:07:28 by sperez-l          #+#    #+#             */
/*   Updated: 2026/03/03 16:07:32 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	get_disorder_index(int n, t_list *stack_a)
{
	t_list	*tmp;
	float	even_total;
	float	errors;
	float	index;

	if (n == 1)
		return (0);
	even_total = (float)(n * (n - 1)) / 2.0f;
	errors = 0;
	while (stack_a && stack_a->next)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (stack_a->content > tmp->content)
				errors++;
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	index = (errors / even_total) * 100.0f;
	return (index);
}
