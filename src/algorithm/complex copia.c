/*
La idea es:
Primero convertir valores a índices y entonces ordenar por bits
Es el sistema (RADIX) que da menos operaciones (para 500, son unas 4500) 
*/

#include "push_swap.h"

void	fill_array(t_stack *a, int *arr)
{
	int	i;

	i = 0;
	while (a)
	{
		arr[i++] = a->value;
		a = a->next;
	}
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size -1)
	{
		if (arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	assign_index(t_stack *a, int *arr, int size)
{
	int	i;

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
}

void	index_stack(t_stack *a)
{
	int	*arr;
	int	size;

	size = stack_size(a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	fill_array(a, arr);
	sort_array(arr, size);
	assign_index(a, arr, size);
	free(arr);
}

void	complex_algo(t_stack **a, t_stack **b, t_bench *bench)
{
	index_stack(*a);
	radix_lsd(a, b, bench);
}
