/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:50:24 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/23 18:53:18 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *argv_char)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	while (argv_char[i])
	{
		while (argv_char[i] == ' ' || (argv_char[i] >= 9 && argv_char[i] <= 13)
			|| argv_char[i] == 39)
			i++;
		if (argv_char[i] == '-' || argv_char[i] == '+')
		{
			if (argv_char[i] == '-')
				sign = -1;
			i++;
		}
		while (argv_char[i] >= '0' && argv_char[i] <= '9')
		{
			result = result * 10 + (argv_char[i] - '0');
			i++;
		}
	}
	return (result * sign);
}
/*
int	main(int argc, char **argv)
{
	long	res;
	int		debug_argc;
	char	*debug_input;
	long	debug_res;

	debug_argc = argc;
	if (argc != 2)
	{
		printf("Use: %s <nummber>\n", argv[0]);
		return (1);
	}
	debug_input = argv[1];
	res = ft_atol(debug_input);
	debug_res = res;
	printf("Input: %s\n", debug_input);
	printf("Result: %ld\n", debug_res);
	return (0);
}
*/
