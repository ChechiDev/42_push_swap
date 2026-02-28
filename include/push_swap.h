/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:29:01 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/27 11:13:13 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

/* Data structure */
typedef enum s_flag_opt
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	BENCH,
	UNDEFINED
}	t_flag_opt;

typedef struct check_flags
{
	int	bench;
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
}	t_flags;

typedef struct s_options
{
	t_flag_opt	*options;
	int			count;
}	t_options;

typedef struct s_stacks
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		start;
	int		end;
}	t_stacks;

typedef struct s_stats
{
	size_t			ra_count;
	size_t			rb_count;
	size_t			rr_count;
	size_t			rra_count;
	size_t			rrb_count;
	size_t			rrr_count;
	size_t			pa_count;
	size_t			pb_count;
	size_t			sa_count;
	size_t			sb_count;
	size_t			ss_count;
	size_t			total_count;
	size_t			sizea;
	t_flag_opt		algo;
	int				isbench;
	int				isadaptive;
	float			di;
}	t_stats;

/* Check */
int		check_first(int argc, char **argv, t_stacks stack);
int		check_flags(int argc, char **argv, t_flags *flags);
int		check_options(t_options **options);
int		check_minmax(char **argv);
int		check_num(char **argv);
int		check_duplicates(char **argv);

/* Parse */
int		parse_options(int argc, char **argv, t_options **options);
int		parse_params(int argc, char **argv, t_list **stack_a);
float	parse_disorder_index(int n, t_list *stack_a);

/* Free */
void	free_list(t_list *stack_a);
void	free_all(t_list **stack_a, t_list **stack_b, t_options **options);

/* Utils */
int		add_node(char *argv, t_list **stack_a);
int		get_argv_opt(int argc, char **argv, int *bench, t_flag_opt *algorithm);
int		get_option(t_flag_opt *opt, t_stats *st, t_options *o);

/* Print */
void	print_stack(t_list *stack, char *label);

/* Movements */
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

/* Algorithm */
double		disorder_meter(t_list *stack_a);
void		simple(t_list **stack_a, t_list **stack_b);
void		last_three(t_list **stack_a, t_list **stack_b);
void		sort_3(t_list **stack_a);

#endif
