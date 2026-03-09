/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:29:01 by sperez-l          #+#    #+#             */
/*   Updated: 2026/03/09 19:09:27 by sperez-l         ###   ########.fr       */
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
	size_t			size_a;
	t_flag_opt		algorithm;
	int				isbench;
	int				isadaptive;
	float			dis_index;
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
float	get_disorder_index(int n, t_list *stack_a);
double	disorder_meter(t_list *stack_a);
void	simple(t_list **stack_a, t_list **stack_b);
void	last_three(t_list **stack_a, t_list **stack_b);
void	sort_3(t_list **stack_a);
void	medium(t_stacks s);
void	get_chunks(t_stacks s, long *arr);
int		get_n_chunks(int n);
int		in_range(t_list *stack_a, long *arr, int start, int end);
void	nearest_number(t_stacks s, long *arr);
int		get_top_pos(t_list *stack_a, long *arr, int start, int end);
int		get_bottom_pos(t_list *stack_a, long *arr, int start, int end);
void	push_to_a(t_stacks s);
int		get_max_pos(t_list *stack_b);
void	complex_algorithm(t_list **a, t_list **b);
void	radix_lsd(t_list **a, t_list **b);
void	index_stack(t_list *a);
void	assign_index(t_list *a, long *arr, int size);
int		max_index_bits(t_list *a);

void	get_algorithm(t_flag_opt opt, t_stacks stack, t_stats **stats);
void	set_adaptive(t_stacks stack, t_options **options);

/* Bench */
void	bench_count(t_stats **stats);
void	bench_print_info(t_stats **stats, t_flag_opt opt);
void	print_each_count(t_stats *s);
void	print_bench_strategy(t_stats *s, t_flag_opt opt);
void	print_disorder(t_stats *s);

#endif
