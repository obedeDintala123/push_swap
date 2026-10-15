/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalata <cpalata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:05:33 by cpalata           #+#    #+#             */
/*   Updated: 2026/10/14 19:51:05 by cpalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_no **pilha)
{
	t_no	*top;
	t_no	*second;

	if (*pilha == NULL || (*pilha)->next == NULL)
		return ;
	top = *pilha;
	second = (*pilha)->next;
	*pilha = second;
	(*pilha)->next = top;
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
