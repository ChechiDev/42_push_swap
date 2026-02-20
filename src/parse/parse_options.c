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

t_flagtype	switch_option(char	*option)
{
	if ((ft_strcmp(option, "bench")) == 0)
		return (BENCH);
	else if ((ft_strcmp(option, "simple")) == 0)
		return (SIMPLE);
	else if ((ft_strcmp(option, "medium")) == 0)
		return (MEDIUM);
	else if ((ft_strcmp(optio, "complex")) == 0)
		return (COMPLEX);
	esle if ((ft_strcmp ("adaptative")) == 0)
		return (ADAPTATIVE);
	return (UNDEFINED);
}
