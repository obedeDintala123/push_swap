/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:05:33 by cpalata           #+#    #+#             */
/*   Updated: 2026/10/19 18:31:43 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_no **pilha)
{
	t_no	*second;
	t_no	*first;

	if (!*pilha || !(*pilha)->next)
		return ;
	first = *pilha;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*pilha = second;
}

void	sa(t_no **pilha, t_bench *bench)
{
	swap(pilha);
	bench_count(bench, "sa");
	ft_printf("sa\n");
}

void	sb(t_no **pilha, t_bench *bench)
{
	swap(pilha);
	bench_count(bench, "sb");
	ft_printf("sb\n");
}

void	ss(t_no **pilha_a, t_no **pilha_b, t_bench *bench)
{
	swap(pilha_a);
	swap(pilha_b);
	bench_count(bench, "ss");
	ft_printf("ss\n");
}
