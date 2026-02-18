/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:29:01 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/18 19:18:06 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/include/libft.h"

/* Data structure */
typedef enum s_flag_opt
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	BENCH,
	UNDEFINED
}	t_flagtype;

typedef struct s_options
{
	t_flagtype	*options;
	int			count;
}	t_options;

typedef struct s_stacks
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		start;
	int		end;
}	t_stacks;

/* Parse */
/* Functions */
void	clear_stash(char **stash);


#endif 
