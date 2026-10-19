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

void	sa(t_no **pilha)
{
	swap(pilha);
}

void	sb(t_no **pilha)
{
	swap(pilha);
}

void	ss(t_no **pilha_a, t_no **pilha_b)
{
	sa(pilha_a);
	sb(pilha_b);
}
