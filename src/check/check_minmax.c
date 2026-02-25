/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:04:40 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/25 18:54:40 by sperez-l         ###   ########.fr       */
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
