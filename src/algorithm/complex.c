/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javisan2 <javisan2@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:00:16 by javisan2          #+#    #+#             */
/*   Updated: 2026/03/10 12:29:32 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
La idea es:
Primero convertir valores a índices y entonces ordenar por bits
Es el sistema (RADIX) que da menos operaciones (para 500, son unas 4500) 

max_index_bits:
Devuelve el número de bits necesarios para representar el índice máximo
while ((max >> bits) != 0) hace:
max >> 0 = 1101 (13)
max >> 1 = 0110 (6)
max >> 2 = 0011 (3)
max >> 3 = 0001 (1)
max >> 4 = 0000 (0) → se termina el bucle

assign_index:
Asigna los índices a cada nodo según su posición ordenada

index_stack:
Crea el array ordenado y llama a assign_index

radix_lsd:
Algoritmo radix (LSD) optimizado para ahorrar la última vuelta
*/

#include "libft.h"
#include "push_swap.h"

/*
void	index_stack(t_stack *a)
{
	long	*arr;
	int		size;
	int		i;

	size = stack_size(a);
	arr = array_sort(a, size);
	if (!arr)
		return ;
	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a->value == arr[i])
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
	free(arr);
}
*/

int	max_index_bits(t_list *a)
{
	int	max;
	int	bits;

	max = 0;
	bits = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	assign_index(t_list *a, long *arr, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a->content == arr[i])
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

void	index_stack(t_list *a)
{
	long	*arr;
	int		size;

	size = ft_lstsize(a);
	arr = array_sort(a, size);
	if (!arr)
		return ;
	assign_index(a, arr, size);
	free(arr);
}

void	radix_lsd(t_list **a, t_list **b, t_stats **bench)
{
	int		i;
	int		j;
	int		max_bits;

	max_bits = max_index_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = ft_lstsize(*a);
		while (j-- > 0)
		{
			if (((*a)->index >> i) & 1)
				ra(a, bench);
			else
				pb(a, b, bench);
		}
		while (*b)
			pa(a, b, bench);
		i++;
	}
}

void	complex_algorithm(t_list **a, t_list **b, t_stats **bench)
{
	index_stack(*a);
	radix_lsd(a, b, bench);
}
