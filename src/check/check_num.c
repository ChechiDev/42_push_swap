/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:05:40 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/23 18:14:18 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
{
	int	j;

	j = 0;
	while (str[j] == ' ' || (str[j] >= 9 && str[j] <= 13) || str[j] == 39)
		j++;
	if (str[j] == '-' || str[j] == '+')
		j++;
	if (str[j] == '\0')
		return (0);
	while (str[j])
	{
		if (!(str[j] >= '0' && str[j] <= '9'))
			return (0);
		j++;
	}
	return (1);
}

int	check_num(char **argv)
{
	int	i;
	int	numbers;

	i = 0;
	numbers = 0;
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
			return (0);
		numbers++;
		i++;
	}
	if (numbers == 0 || !check_duplicates(argv))
		return (0);
	return (1);
}
