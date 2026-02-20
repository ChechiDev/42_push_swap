/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:35:01 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/20 13:18:31 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_opttype	switch_option(char	*opt_str)
{
	if ((ft_strcmp(opt_str, "bench")) == 0)
		return (BENCH);
	else if ((ft_strcmp(opt_str, "simple")) == 0)
		return (SIMPLE);
	else if ((ft_strcmp(opt_str, "medium")) == 0)
		return (MEDIUM);
	else if ((ft_strcmp(opt_str, "complex")) == 0)
		return (COMPLEX);
	esle if ((ft_strcmp (opt_str, "adaptative")) == 0)
		return (ADAPTATIVE);
	return (UNDEFINED);
}


int	parse_options(int ac, char **av, t_opttype **options)
{
	t_opttype	alg;
	int	bench;
	int	error;

	alg = UNDEFINED;
	bench = 0;
	*options = malloc(sizeof(t_opttype);
	if (!*options)
		return (0);
	(*options)->count = 0;
	(*options)->options = malloc(2 * sizeof(t_opttype));
	if (!(*options)->options)
		return (free(*options), 0);
	>>>ERROR FUNCION<<<(ac, av, bench, alg); // nombre de función a definir
	if (error)
		return (error);
	if (bench == 1)
		(*options)->options[(*options)->count++] = BENCH;
	if (alg != UNDEFINED)
		(*options)->options[(*options)->count++] = alg;
	return ((*options)->count);
}
