/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:02:04 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/26 18:02:33 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_list	*stack;
	char	*argv_ok[] = {"prog", "3", "2", "1", NULL};
	char	*argv_flag[] = {"prog", "--simple", "3", "2", "1", NULL};
	char	*argv_dup[] = {"prog", "3", "3", "1", NULL};
	char	*argv_big[] = {"prog", "2147483648", NULL};
	char	*argv_str[] = {"prog", "abc", NULL};
	int		result;

	printf("=== TEST parse_params ===\n\n");
	printf("-- Numeros validos [3,2,1] -> 1\n");
	stack = NULL;
	result = parse_params(4, argv_ok, &stack);
	printf("retorno: %d (esp: 1)\n", result);
	print_stack(stack, "stack_a");
	free_list(stack);
	printf("\n-- Con flag --simple [3,2,1] -> 1\n");
	stack = NULL;
	result = parse_params(5, argv_flag, &stack);
	printf("retorno: %d (esp: 1)\n", result);
	print_stack(stack, "stack_a");
	free_list(stack);
	printf("\n-- Duplicados [3,3,1] -> 0\n");
	stack = NULL;
	result = parse_params(4, argv_dup, &stack);
	printf("retorno: %d (esp: 0)\n", result);
	printf("\n-- Overflow [2147483648] -> 0\n");
	stack = NULL;
	result = parse_params(2, argv_big, &stack);
	printf("retorno: %d (esp: 0)\n", result);
	printf("\n-- String [abc] -> 0\n");
	stack = NULL;
	result = parse_params(2, argv_str, &stack);
	printf("retorno: %d (esp: 0)\n", result);
	return (0);
}
