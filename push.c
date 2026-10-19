/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 18:05:49 by cpalata           #+#    #+#             */
/*   Updated: 2026/10/19 16:59:05 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_no **pilha_a, t_no **pilha_b)
{
	t_no	*top_b;

	if (!*pilha_b)
		return ;
	top_b = *pilha_b;
	*pilha_b = top_b->next;
	top_b->next = *pilha_a;
	*pilha_a = top_b;
}

void	push_b(t_no **pilha_a, t_no **pilha_b)
{
	t_no	*top_a;

	if (!*pilha_a)
		return ;
	top_a = *pilha_a;
	*pilha_a = top_a->next;
	top_a->next = *pilha_b;
	*pilha_b = top_a;
}
