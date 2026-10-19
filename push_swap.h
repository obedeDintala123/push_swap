/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalata <cpalata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:18:49 by cpalata           #+#    #+#             */
/*   Updated: 2026/10/16 13:11:50 by cpalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include	<stdlib.h>

typedef struct no
{
	int			value;
	struct no	*next;
}	t_no;
void	push_a(t_no **pilha_a, t_no **pilha_b);
void	push_b(t_no **pilha_b, t_no **pilha_a);
void	rotate_a(t_no **pilha);
void	rotate_b(t_no **pilha);
void	rr_rotate(t_no **pilha_a, t_no **pilha_b);
void    reverse_a(t_no **pilha_a);
void    reverse_b(t_no **pilha_b);
void    rrr_reverse(t_no **pilha_a, t_no **pilha_b);
void	sa(t_no **pilha);
void	sb(t_no **pilha);
void	ss(t_no **pilha_a, t_no **pilha_b);

#endif
