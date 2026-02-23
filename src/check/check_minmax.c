/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:04:40 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/23 19:29:18 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	check_minmax(char **argv)
{
	int		i;
	long	num;

	i = 0;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

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

	result = check_minmax(input_values);
	debug_result = result;

	printf("Result: %d\n", debug_result);
	if (debug_result == 1)
		printf("All values inside INT range\n");
	else
		printf("Value outside INT range detected\n");

	return (0);
}
