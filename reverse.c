/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 09:26:26 by cpalata           #+#    #+#             */
/*   Updated: 2026/10/19 18:49:29 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_no **pilha)
{
	t_no	*first;
	t_no	*last;
	t_no	*current;

	if (!*pilha || !(*pilha)->next)
		return ;
	first = *pilha;
	last = *pilha;
	current = *pilha;
	while (last->next)
		last = last->next;
	while (current->next->next)
		current = current->next;
	last->next = first;
	current->next = NULL;
	*pilha = last;
}

void	reverse_a(t_no **pilha_a, t_bench *bench)
{
	reverse(pilha_a);
	bench_count(bench, "rra");
	ft_printf("rra\n");
}

void	reverse_b(t_no **pilha_b, t_bench *bench)
{
	reverse(pilha_b);
	bench_count(bench, "rrb");
	ft_printf("rrb\n");
}

void	rrr_reverse(t_no **pilha_a, t_no **pilha_b, t_bench *bench)
{
	reverse(pilha_a);
	reverse(pilha_b);
	bench_count(bench, "rrr");
	ft_printf("rrr\n");
}
