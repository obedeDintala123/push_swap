/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:03:13 by obdintal          #+#    #+#             */
/*   Updated: 2026/10/27 00:00:00 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_summary(t_sort_run *run)
{
	size_t	total;
	int		percent;

	total = run->bench.sa + run->bench.sb + run->bench.ss + run->bench.pa
		+ run->bench.pb + run->bench.ra + run->bench.rb + run->bench.rr
		+ run->bench.rra + run->bench.rrb + run->bench.rrr;
	percent = (int)(run->disorder.ratio * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(percent / 100, 2);
	ft_putchar_fd('.', 2);
	ft_putchar_fd('0' + (percent / 10) % 10, 2);
	ft_putchar_fd('0' + percent % 10, 2);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	ft_putstr_fd(run->strategy, 2);
	ft_putstr_fd("\n[bench] complexity: ", 2);
	ft_putstr_fd(run->complexity, 2);
	ft_putstr_fd("\n[bench] input size: ", 2);
	ft_putnbr_fd(run->size, 2);
	ft_putstr_fd("\n[bench] operations: ", 2);
	ft_putnbr_fd((int)total, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_swaps(t_bench *bench)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd((int)bench->sa, 2);
	ft_putstr_fd(" | sb: ", 2);
	ft_putnbr_fd((int)bench->sb, 2);
	ft_putstr_fd(" | ss: ", 2);
	ft_putnbr_fd((int)bench->ss, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_pushes(t_bench *bench)
{
	ft_putstr_fd("[bench] pa: ", 2);
	ft_putnbr_fd((int)bench->pa, 2);
	ft_putstr_fd(" | pb: ", 2);
	ft_putnbr_fd((int)bench->pb, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_rotations(t_bench *bench)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd((int)bench->ra, 2);
	ft_putstr_fd(" | rb: ", 2);
	ft_putnbr_fd((int)bench->rb, 2);
	ft_putstr_fd(" | rr: ", 2);
	ft_putnbr_fd((int)bench->rr, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] rra: ", 2);
	ft_putnbr_fd((int)bench->rra, 2);
	ft_putstr_fd(" | rrb: ", 2);
	ft_putnbr_fd((int)bench->rrb, 2);
	ft_putstr_fd(" | rrr: ", 2);
	ft_putnbr_fd((int)bench->rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	bench_report(t_sort_run *run)
{
	print_summary(run);
	print_swaps(&run->bench);
	print_pushes(&run->bench);
	print_rotations(&run->bench);
}
