/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalata <cpalata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:41:35 by cpalata           #+#    #+#             */
/*   Updated: 2026/10/23 18:28:12 by cpalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_reset(t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

void	bench_count(t_bench *bench, char *operation)
{
	if (ft_strncmp(operation, "sa", 3) == 0)
		bench->sa++;
	else if (ft_strncmp(operation, "sb", 3) == 0)
		bench->sb++;
	else if (ft_strncmp(operation, "ss", 3) == 0)
		bench->ss++;
	else if (ft_strncmp(operation, "pa", 3) == 0)
		bench->pa++;
	else if (ft_strncmp(operation, "pb", 3) == 0)
		bench->pb++;
	else if (ft_strncmp(operation, "ra", 3) == 0)
		bench->ra++;
	else if (ft_strncmp(operation, "rb", 3) == 0)
		bench->rb++;
	else if (ft_strncmp(operation, "rr", 3) == 0)
		bench->rr++;
	else if (ft_strncmp(operation, "rra", 4) == 0)
		bench->rra++;
	else if (ft_strncmp(operation, "rrb", 4) == 0)
		bench->rrb++;
	else if (ft_strncmp(operation, "rrr", 4) == 0)
		bench->rrr++;
}
