/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:39:17 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/23 13:51:50 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "push_swap.h"

int	check_flags(int argc, char **argv, t_flags flags)
{
	int	i;
	int	f;

	i = 1;
	f = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strcmp(argv[i], "--bench") == 0 && !flags.bench)
			flags.bench = 1;
		else if (ft_strcmp(argv[i], "--simple") == 0 && !flags.simple && !f)
			flags.simple = 1;
		else if (ft_strcmp(argv[i], "--medium") == 0 && !flags.medium && !f)
			flags.medium = 1;
		else if (ft_strcmp(argv[i], "--complex") == 0 && !flags.complex && !f)
			flags.complex = 1;
		else if (ft_strcmp(argv[i], "--adaptive") == 0 && !flags.adaptive && !f)
			flags.adaptive = 1;
		else
			return (-1);
		if (ft_strcmp(argv[i], "--bench") != 0)
			f = 1;
		i++;
	}
	return (i);
}
