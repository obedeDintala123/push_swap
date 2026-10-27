/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:55:06 by obdintal          #+#    #+#             */
/*   Updated: 2026/10/27 00:00:00 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_mode(char **argv, t_sort_run *run)
{
	int	i;

	run->mode = "--adaptive";
	run->bench_enabled = 0;
	i = 1;
	while (argv[i] && ft_is_flag(argv[i]))
	{
		if (ft_is_mode(argv[i]))
			run->mode = argv[i];
		if (ft_is_opt(argv[i], "--bench"))
			run->bench_enabled = 1;
		i++;
	}
	run->adaptive = ft_is_opt(run->mode, "--adaptive");
	if (run->adaptive && run->disorder.mistakes * 5 < run->disorder.total_pairs)
		run->mode = "--simple";
	else if (run->adaptive
		&& run->disorder.mistakes * 2 < run->disorder.total_pairs)
		run->mode = "--medium";
	else if (run->adaptive)
		run->mode = "--complex";
}

static void	set_strategy(t_sort_run *run)
{
	if (ft_is_opt(run->mode, "--simple"))
	{
		run->strategy = "simple";
		run->complexity = "O(n^2)";
	}
	else if (ft_is_opt(run->mode, "--medium"))
	{
		run->strategy = "medium";
		run->complexity = "O(n sqrt(n))";
	}
	else
	{
		run->strategy = "complex";
		run->complexity = "O(n log n)";
	}
	if (run->adaptive)
	{
		if (ft_is_opt(run->mode, "--complex"))
			run->strategy = "adaptive (complex)";
		else if (ft_is_opt(run->mode, "--medium"))
			run->strategy = "adaptive (medium)";
		else
			run->strategy = "adaptive (simple)";
	}
}

static void	execute_selected(t_sort_run *run)
{
	set_strategy(run);
	if (ft_is_opt(run->mode, "--simple"))
		select_sort(run->pilha_a, &run->pilha_b, &run->bench);
	else if (ft_is_opt(run->mode, "--medium"))
		chunk_sort(run->pilha_a, &run->pilha_b, &run->bench);
	else
		radix_sort(run->pilha_a, &run->pilha_b, &run->bench);
}

static void	execute_sort(t_sort_run *run)
{
	if (run->adaptive && run->size <= 5)
	{
		run->strategy = "adaptive (small sort)";
		run->complexity = "O(n^2)";
		sort_small(run->pilha_a, &run->pilha_b, &run->bench);
	}
	else
		execute_selected(run);
}

void	ft_chose_method(t_no **pilha_a, char **argv)
{
	t_sort_run	run;

	run.pilha_a = pilha_a;
	run.pilha_b = NULL;
	run.disorder = compute_disorder(*pilha_a);
	init_mode(argv, &run);
	run.size = len_stack(*pilha_a);
	bench_reset(&run.bench);
	if (run.disorder.mistakes == 0)
	{
		run.strategy = "none";
		run.complexity = "O(1)";
	}
	else
	{
		sign_index(*pilha_a);
		execute_sort(&run);
	}
	if (run.bench_enabled)
		bench_report(&run);
}
