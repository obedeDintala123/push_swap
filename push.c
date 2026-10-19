/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalata <cpalata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 18:05:49 by cpalata           #+#    #+#             */
/*   Updated: 2026/10/19 20:48:52 by cpalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_stack(t_no *pilha)
{
	int	size;

	while (pilha)
	{
		size++;
		pilha = pilha->next;
	}
	return (size);
}

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
