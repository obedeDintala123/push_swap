/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalata <cpalata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 07:43:03 by cpalata           #+#    #+#             */
/*   Updated: 2026/10/15 09:57:00 by cpalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_no **pilha)
{
	t_no	*top;
	t_no	*end;

	top = *pilha;
	end = (*pilha)->next;
	(*pilha)->next = top;
	*pilha = end;
}

void	rotate_a(t_no **pilha)
{
	rotate(*pilha);
}

void	rotate_b(t_no **pilha)
{
	rotate(*pilha);
}

void	rr_rotate(t_no **pilha_a, t_no **pilha_b)
{
	rotate_a(*pilha_a);
	rotate_b(*pilha_b);
}
