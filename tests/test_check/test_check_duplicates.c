/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check_duplicates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:32:33 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/25 18:58:31 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	int		arg_count;
	char	**input_values;
	int		result;
	int		debug_result;

	arg_count = argc;
	input_values = argv + 1;
	if (arg_count < 2)
	{
		printf("Usage: %s <num1> <num2> ...\n", argv[0]);
		return (1);
	}
	result = check_duplicates(input_values);
	debug_result = result;
	printf("Result: %d\n", debug_result);
	if (debug_result == 1)
		printf("No duplicates\n");
	else
		printf("Duplicates found\n");
	return (0);
}
