/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalata <cpalata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 21:21:57 by cpalata           #+#    #+#             */
/*   Updated: 2026/10/23 20:01:10 by cpalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int size)
{
	int	max_index;
	int	max_bits;

	max_index = size - 1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_no **pilha_a, t_no **pilha_b, t_bench *bench)
{
	int	size;
	int	max_bits;
	int	bit;
	int	i;

	size = len_stack(*pilha_a);
	if (size < 2)
		return ;
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((*pilha_a)->index >> bit & 1) == 0)
				push_b(pilha_a, pilha_b, bench);
			else
				rotate_a(pilha_a, bench);
			i++;
		}
		while (*pilha_b)
			push_a(pilha_a, pilha_b, bench);
		bit++;
	}
}
