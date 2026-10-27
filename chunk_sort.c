/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalata <cpalata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 19:50:20 by cpalata           #+#    #+#             */
/*   Updated: 2026/10/23 20:15:30 by cpalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_no **a, t_no **b, t_bench *bench)
{
	int	size;
	int	chunk_size;

	size = len_stack(*a);
	if (size < 2)
		return ;
	chunk_size = get_chunk_size(size);
	push_chunks(a, b, chunk_size, bench);
	push_back_to_a(a, b, bench);
}
