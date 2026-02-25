#include "push_swap.h"

int	get_n_chunks(int n)
{
	if (n <=5)
		return (1);
	else if (n <= 50)
		return (2);
	else if (n <= 100)
		return (6);
	else if (n <= 500)
		return (9);
	return (11);
}


void	get_chunks(t_stacks s, long *arr)
{
	int	total_size;
	int	chunks;
	int	size;
	int	i;

	total_size = ft_lstsize(*s.stack_a);
	chunks = get_n_chunks(total_size);
	size = total_size / chunks;
	i = 0;
	while (i < chunks)
	{
		s.start = i *size;
		if (i == chunk - 1)
			s.end = total_size - 1;
		else
			s.end = s.start + size -1;
		while (FUNCION DE RANGO
			FUNC. DE Nº + CERCANO
		i++;
	}
}
