/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:57:42 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/24 12:45:20 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_list **stack_a, t_list **stack_b, t_options **options)
{
	free_list(*stack_a);
	*stack_a = NULL;
	free_list(*stack_b);
	*stack_b = NULL;
	if (options && *options)
	{
		free((*options)->options);
		free(*options);
		*options = NULL;
	}
}
