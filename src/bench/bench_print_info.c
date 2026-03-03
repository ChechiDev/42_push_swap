/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:00:32 by sperez-l          #+#    #+#             */
/*   Updated: 2026/03/03 17:05:46 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_each_count(t_stats *s)
{
	write(2, "[bench] sa:  ", 13);
	ft_putnbr_fd(s->sa_count, 2);
	write(2, "  sb:  ", 7);
	ft_putnbr_fd(s->sb_count, 2);
	write(2, "  ss:  ", 7);
	ft_putnbr_fd(s->ss_count, 2);
	write(2, "  pa:  ", 7);
	ft_putnbr_fd(s->pa_count, 2);
	write(2, "  pb:  ", 7);
	ft_putnbr_fd(s->pb_count, 2);
	write(2, "\n[bench] ra:  ", 14);
	ft_putnbr_fd(s->ra_count, 2);
	write(2, "  rb:  ", 7);
	ft_putnbr_fd(s->rb_count, 2);
	write(2, "  rr:  ", 7);
	ft_putnbr_fd(s->rr_count, 2);
	write(2, "  rra:  ", 8);
	ft_putnbr_fd(s->rra_count, 2);
	write(2, "  rrb:  ", 8);
	ft_putnbr_fd(s->rrb_count, 2);
	write(2, "  rrr:  ", 8);
	ft_putnbr_fd(s->rrr_count, 2);
	write(2, "\n", 1);	
}

void	bench_prin_info(t_stats **stats, t_optype opt)
{
	t_stats	*s;

	if (!stats || !*stats)
		return ;
	s = *stats;
	print_each_count(s);
}
