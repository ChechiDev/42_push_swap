/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:35:01 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/27 11:13:21 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
