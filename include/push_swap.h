/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:29:01 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/18 19:08:56 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/include/libft.h"

/* Data structure */
typedef enum e_flag_opt
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	BENCH,
	UNDEFINED
}	t_flagtype;

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
