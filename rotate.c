/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 07:43:03 by cpalata           #+#    #+#             */
/*   Updated: 2026/10/19 18:31:21 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_no **pilha)
{
	t_no	*first;
	t_no	*last;

	if (!*pilha || !(*pilha)->next)
		return ;
	first = *pilha;
	last = *pilha;
	while (last->next)
		last = last->next;
	*pilha = first->next;
	first->next = NULL;
	last->next = first;
}

void	rotate_a(t_no **pilha, t_bench *bench)
{
	rotate(pilha);
	bench_count(bench, "ra");
	ft_printf("ra\n");
}

void	rotate_b(t_no **pilha, t_bench *bench)
{
	rotate(pilha);
	bench_count(bench, "rb");
	ft_printf("rb\n");
}

void	rr_rotate(t_no **pilha_a, t_no **pilha_b, t_bench *bench)
{
	rotate(pilha_a);
	rotate(pilha_b);
	bench_count(bench, "rr");
	ft_printf("rr\n");
}
