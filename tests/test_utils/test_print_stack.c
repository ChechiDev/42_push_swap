/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:57:17 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/26 17:52:21 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_list	d;
	t_list	c;
	t_list	b;
	t_list	a;

	printf("=== TEST print_stack ===\n\n");
	printf("-- Stack con 3 elementos --\n");
	printf("esperado: [stack_a] 3 2 1\n");
	c = (t_list){1, NULL};
	b = (t_list){2, &c};
	a = (t_list){3, &b};
	print_stack(&a, "stack_a");
	printf("\n-- Stack con 1 elemento --\n");
	printf("esperado: [stack_b] 42\n");
	a = (t_list){42, NULL};
	print_stack(&a, "stack_b");
	printf("\n-- Stack vacio --\n");
	printf("esperado: [stack_a]\n");
	print_stack(NULL, "stack_a");
	printf("\n-- Stack con negativos --\n");
	printf("esperado: [stack_b] -3 -1 0 5\n");
	d = (t_list){5, NULL};
	c = (t_list){0, &d};
	b = (t_list){-1, &c};
	a = (t_list){-3, &b};
	print_stack(&a, "stack_b");
	return (0);
}
