#include "libft.h"

long	*array_sort(t_list *stack, int len)
{
	int	i;
	long	*arr;

	arr = malloc(len * sizeof(long));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len && stack)
	{
		arr[i] = stack->content;
		stack = stack->next;
		i++;
	}
	bubblesort(arr, len);
	return (arr);
}
