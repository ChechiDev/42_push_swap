/*
Algoritmo simple (O(n2)):
Implementa al menos un algoritmo base perteneciente a la clase de
complejidad O(n2).
• Métodos simples de extracción del mínimo/máximo
*/

int	get_min(t_list *stack_a)
{
	int	min;
	int	index_min;
	int	index;

	if (!stack_a)
		return (0);
	min = stack_a->content;
	index_min = 0;
	index = 0;
	while (stack_a)
	{
		if (stack_a->content < min)
		{
			min = stack_a->content;
			index_min = index;
		}
		index++;
		stack_a = stack_a->next;
	}
	return (index_min);
}

void	last_three(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else
		sort_three(stack_a); FUNCION PARA 3 NUMEROS
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	simple(t_list **stack_a, t_list **stack_b) // HA DE LLEGAR UNA PILA A con + de 1 nodo!! ¿Se comprueba antes?
{
	int	nodes_a;
	int	pos_min_a;

	if ESTA ORDENADO
		return ;
	while (ft_lstsize(*stack_a) > 3)
	{
		nodes_a = ft_lstsize(*stack_a);
		pos_min_a = get_min(*stack_a);
		if (pos_min_a <= (nodes_a / 2))
		{
			while (pos_min_a-- != 0)
				ra(stack_a);
		}
		else
		{
			while ((nodes_a - pos_min_a++) != 0)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	last_three(stack_a, stack_b);
}
