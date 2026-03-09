/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:00:32 by sperez-l          #+#    #+#             */
/*   Updated: 2026/03/04 15:03:06 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(t_stats *s)
{
	int	whole;
	int	decimal;

	whole = (int)s->dis_index;
	decimal = (int)(s->dis_index * 100) % 100;
	if (decimal < 0)
		decimal *= -1;
	ft_write(2, "[BENCH] Disorder:  ", 19);
	ft_putnbr_fd(whole, 2);
	ft_write(2, ".", 1);
	if (decimal < 10)
		ft_write(2, "0", 1);
	ft_putnbr_fd(decimal, 2);
	ft_write(2, "%\n", 2);
}

void	print_bench_strategy(t_stats *s, t_flag_opt opt)
{
	if (s->algorithm == SIMPLE)
		ft_write(2, "[BENCH] Strategy:  Simple / O(n^2)\n", 35);	
	else if (s->algorithm == MEDIUM)
		ft_write(2, "[BENCH] Strategy:  Medium / O(n√n)\n", 37);
	else if (s->algorithm == COMPLEX)
		ft_write(2, "[BENCH] Strategy:  Complex / O(n log n)\n", 40);
	else if (s->algorithm == ADAPTIVE)
	{
		ft_write(2, "[BENCH] Strategy:  Adaptive / ", 30);
		if (opt == SIMPLE)
			ft_write(2, "O(n^2)\n", 8);
		else if (opt == MEDIUM)
			ft_write(2, "O(n√n)\n", 9);
		else if (opt == COMPLEX)
			ft_write(2, "O(n log n)\n", 11);
	}
	ft_write(2, "[BENCH] Total_ops:  ", 20);
	ft_putnbr_fd(s->total_count, 2);
	ft_write(2, "\n", 1);
}

void	print_each_count(t_stats *s)
{
	ft_write(2, "[BENCH] sa:  ", 13);
	ft_putnbr_fd(s->sa_count, 2);
	ft_write(2, "  sb:  ", 7);
	ft_putnbr_fd(s->sb_count, 2);
	ft_write(2, "  ss:  ", 7);
	ft_putnbr_fd(s->ss_count, 2);
	ft_write(2, "  pa:  ", 7);
	ft_putnbr_fd(s->pa_count, 2);
	ft_write(2, "  pb:  ", 7);
	ft_putnbr_fd(s->pb_count, 2);
	ft_write(2, "\n[BENCH] ra:  ", 14);
	ft_putnbr_fd(s->ra_count, 2);
	ft_write(2, "  rb:  ", 7);
	ft_putnbr_fd(s->rb_count, 2);
	ft_write(2, "  rr:  ", 7);
	ft_putnbr_fd(s->rr_count, 2);
	ft_write(2, "  rra:  ", 8);
	ft_putnbr_fd(s->rra_count, 2);
	ft_write(2, "  rrb:  ", 8);
	ft_putnbr_fd(s->rrb_count, 2);
	ft_write(2, "  rrr:  ", 8);
	ft_putnbr_fd(s->rrr_count, 2);
	ft_write(2, "\n", 1);	
}

void	bench_print_info(t_stats **stats, t_flag_opt opt)
{
	t_stats	*s;

	if (!stats || !*stats)
		return ;
	s = *stats;
	print_disorder(s);
	print_bench_strategy(s, opt);
	print_each_count(s);
}
