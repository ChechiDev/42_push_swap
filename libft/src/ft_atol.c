/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:50:24 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/26 15:33:35 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign(char *argv_char, int *i)
{
	while (argv_char[*i] == ' ' || (argv_char[*i] >= 9
			&& argv_char[*i] <= 13))
		(*i)++;
	if (argv_char[*i] == '-' || argv_char[*i] == '+')
	{
		if (argv_char[*i] == '-')
		{
			(*i)++;
			return (-1);
		}
		(*i)++;
	}
	return (1);
}

long	ft_atol(char *argv_char)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = get_sign(argv_char, &i);
	while (argv_char[i] >= '0' && argv_char[i] <= '9')
	{
		if (result > (LONG_MAX - (argv_char[i] - '0')) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		result = result * 10 + (argv_char[i] - '0');
		i++;
	}
	return (result * sign);
}
