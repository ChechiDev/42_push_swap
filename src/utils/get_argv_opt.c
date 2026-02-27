/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:08:30 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/27 11:09:29 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_flag_opt	switch_option(char *opt_str)
{
	if ((ft_strcmp(opt_str, "bench")) == 0)
		return (BENCH);
	else if ((ft_strcmp(opt_str, "simple")) == 0)
		return (SIMPLE);
	else if ((ft_strcmp(opt_str, "medium")) == 0)
		return (MEDIUM);
	else if ((ft_strcmp(opt_str, "complex")) == 0)
		return (COMPLEX);
	else if ((ft_strcmp (opt_str, "adaptive")) == 0)
		return (ADAPTIVE);
	return (UNDEFINED);
}

int	get_argv_opt(int argc, char **argv, int *bench, t_flag_opt *algorithm)
{
	int			i;
	t_flag_opt	opt;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
		{
			if (*bench)
				return (3);
			*bench = 1;
		}
		else if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			opt = switch_option(&argv[i][2]);
			if (opt != UNDEFINED && opt != BENCH)
			{
				if (*algorithm != UNDEFINED && *algorithm != opt)
					return (3);
				*algorithm = opt;
			}
		}
		i++;
	}
	return (0);
}

