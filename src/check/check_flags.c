/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:39:17 by sperez-l          #+#    #+#             */
/*   Updated: 2026/03/03 13:27:37 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	set_flag(char *arg, t_flags *flags, int *f)
{
	if (ft_strcmp(arg, "--bench") == 0 && !flags->bench)
		return (flags->bench = 1, 1);
	if (ft_strcmp(arg, "--simple") == 0 && !flags->simple && !*f)
		return (flags->simple = 1, *f = 1, 1);
	if (ft_strcmp(arg, "--medium") == 0 && !flags->medium && !*f)
		return (flags->medium = 1, *f = 1, 1);
	if (ft_strcmp(arg, "--complex") == 0 && !flags->complex && !*f)
		return (flags->complex = 1, *f = 1, 1);
	if (ft_strcmp(arg, "--adaptive") == 0 && !flags->adaptive && !*f)
		return (flags->adaptive = 1, *f = 1, 1);
	return (0);
}

int	check_flags(int argc, char **argv, t_flags *flags)
{
	int	i;
	int	f;

	if (!flags)
		return (-1);
	i = 1;
	f = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!set_flag(argv[i], flags, &f))
			return (-1);
		i++;
	}
	return (i);
}
