/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:35:01 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/24 16:13:03 by sperez-l         ###   ########.fr       */
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

int	select_option(t_flag_opt *opt, t_stats *st, t_options *o)
{
	if (o->count == 2)
	{
		st->isbench = 1;
		if (o->options[0] != BENCH)
			*opt = o->options[0];
		else
			*opt = o->options[1];
	}
	else if (o->count == 1)
	{
		if (o->options[0] == BENCH)
		{
			st->isbench = 1;
			st->isadaptive = 1;
		}
		else
			*opt = o->options[0];
	}
	return (1);
}

int	parse_options(int argc, char **argv, t_options **options)
{
	t_flag_opt	algorithm;
	int			bench;
	int			error;

	algorithm = UNDEFINED;
	bench = 0;
	*options = malloc(sizeof(t_options));
	if (!*options)
		return (0);
	(*options)->count = 0;
	(*options)->options = malloc(2 * sizeof(t_flag_opt));
	if (!(*options)->options)
		return (free(*options), 0);
	error = get_argv_opt(argc, argv, &bench, &algorithm);
	if (error)
		return (error);
	if (bench == 1)
		(*options)->options[(*options)->count++] = BENCH;
	if (algorithm != UNDEFINED)
		(*options)->options[(*options)->count++] = algorithm;
	return ((*options)->count);
}
