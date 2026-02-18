/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:35:01 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/18 16:47:02 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_flagtype	switch_option(char	*option)
{
	if ((ft_strcmp(optionstr, "bench")) == 0)
		return (BENCH);

	return (UNDEFINED);
}
