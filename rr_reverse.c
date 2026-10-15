/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalata <cpalata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 09:26:26 by cpalata           #+#    #+#             */
/*   Updated: 2026/10/15 10:03:56 by cpalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    reverse(t_no **pilha)
{
    t_no    *end;
    
    end = (*pilha)->next;
    *pilha = (*pilha)->next;
    *pilha = end;
}
void    reverse_a(t_no **pilha_a)
{
    reverse(*pilha_a);
}
void    reverse_b(t_no **pilha_b)
{
    reverse(*pilha_b);
}
void    rrr_reverse(t_no **pilha_a, t_no **pilha_b)
{
    reverse(*pilha_a);
    reverse(pilha_b);
}