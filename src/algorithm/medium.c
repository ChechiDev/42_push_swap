/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javisan2 <javisan2@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:31:13 by javisan2          #+#    #+#             */
/*   Updated: 2026/03/10 12:22:46 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
El algoritmo por rangos reduce el número de rotaciones porque
cada elemento se empuja una sola vez y la pila B se prepara
durante la fase de envío, de modo que la reconstrucción final
requiere muy pocos movimientos.

En el header tenemos esta struct:
typedef struct s_stacks
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		start;
	int		end;
}	t_stacks;
*/
// Esta funcion (get_bottom_pos) la llamo desde medium_chunks.c
//La pongo aquí porque sobraba espacio, en medium_chunks ya hay 5 funciones.

#include "push_swap.h"

int	get_bottom_pos(t_list *stack_a, long *arr, int start, int end)
{
	int	i;
	int	bottom;

	i = 0;
	bottom = -1;
	while (stack_a)
	{
		if (stack_a->content >= arr[start] && stack_a->content <= arr[end])
			bottom = i;
		stack_a = stack_a->next;
		i++;
	}
	return (bottom);
}

int	get_max_pos(t_list *stack_b)
{
	int	pos;
	int	max_pos;
	int	max_val;

	pos = 0;
	max_pos = 0;
	max_val = stack_b->content;
	while (stack_b)
	{
		if (stack_b->content > max_val)
		{
			max_val = stack_b->content;
			max_pos = pos;
		}
		stack_b = stack_b->next;
		pos++;
	}
	return (max_pos);
}

void	push_to_a(t_stacks s, t_stats **bench)
{
	int	max_pos;
	int	size;

	while (*s.stack_b)
	{
		max_pos = get_max_pos(*s.stack_b);
		size = ft_lstsize(*s.stack_b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(s.stack_b, bench);
		}
		else
		{
			max_pos = size - max_pos;
			while (max_pos-- > 0)
				rrb(s.stack_b, bench);
		}
		pa(s.stack_a, s.stack_b, bench);
	}
}

void	medium(t_stacks s, t_stats **bench)
{
	long	*arr;
	int		size;
	float	disorder;

	size = ft_lstsize(*s.stack_a);
	if (size == 1)
		return ;
	disorder = get_disorder_index(size, *s.stack_a);
	if (disorder == 0)
		return ;
	arr = array_sort(*s.stack_a, size);
	if (!arr)
		return ;
	get_chunks(s, arr, bench);
	push_to_a(s, bench);
	free(arr);
}
