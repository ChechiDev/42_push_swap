/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_disorder_index.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:54:52 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/26 19:03:07 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*make_list(long *vals, int n)
{
	t_list	*head;
	t_list	*node;
	int		i;

	head = NULL;
	i = 0;
	while (i < n)
	{
		node = ft_lstnew(vals[i]);
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}

static void	print_list_stdout(t_list *stack)
{
	while (stack)
	{
		printf("%ld ", stack->content);
		stack = stack->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*stack;
	long	sorted[4] = {1, 2, 3, 4};
	long	reversed[4] = {4, 3, 2, 1};
	long	single[1] = {42};
	long	two_ok[2] = {1, 2};
	long	two_ko[2] = {2, 1};

	printf("=== TEST parse_disorder_index ===\n\n");

	printf("-- 1 elemento\n");
	stack = make_list(single, 1);
	printf("stack: ");
	print_list_stdout(stack);
	printf("resultado: %.2f (esperado: 0.00)\n\n",
		parse_disorder_index(1, stack));
	free_list(stack);

	printf("-- Ordenado\n");
	stack = make_list(sorted, 4);
	printf("stack: ");
	print_list_stdout(stack);
	printf("resultado: %.2f (esperado: 0.00)\n\n",
		parse_disorder_index(4, stack));
	free_list(stack);

	printf("-- Invertido (todos desordenados)\n");
	stack = make_list(reversed, 4);
	printf("stack: ");
	print_list_stdout(stack);
	printf("resultado: %.2f (esperado: 1.00)\n\n",
		parse_disorder_index(4, stack));
	free_list(stack);

	printf("-- 2 elementos ordenados\n");
	stack = make_list(two_ok, 2);
	printf("stack: ");
	print_list_stdout(stack);
	printf("resultado: %.2f (esperado: 0.00)\n\n",
		parse_disorder_index(2, stack));
	free_list(stack);

	printf("-- 2 elementos invertidos\n");
	stack = make_list(two_ko, 2);
	printf("stack: ");
	print_list_stdout(stack);
	printf("resultado: %.2f (esperado: 1.00)\n\n",
		parse_disorder_index(2, stack));
	free_list(stack);

	return (0);
}
