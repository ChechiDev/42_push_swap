/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javisan2 <javisan2@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:30:05 by javisan2          #+#    #+#             */
/*   Updated: 2026/03/04 17:30:13 by javisan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Está calculando el ratio de pares desordenados.
RETURN:
Número de inversiones / número total de pares posibles
*/

#include "libft.h"
#include "push_swap.h"

double	disorder_meter(t_list *stack_a)
{
	t_list	*i;
	t_list	*j;
	int		wrong_pairs;
	int		total_pairs;

	i = stack_a;
	wrong_pairs = 0;
	total_pairs = 0;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->content > j->content)
				wrong_pairs++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double) wrong_pairs / (double) total_pairs);
}
