/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalata <cpalata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 19:36:24 by cpalata           #+#    #+#             */
/*   Updated: 2026/10/23 20:34:22 by cpalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	raiz(int n)
{
	int	root;

	if (n < 0)
		return (0);
	root = 0;
	while (root <= n / (root + 1))
		root++;
	return (root);
}

int	get_max_index_position(t_no *stack)
{
	int	max_index;
	int	position;
	int	max_position;

	max_index = stack->index;
	position = 0;
	max_position = 0;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_position = position;
		}
		position++;
		stack = stack->next;
	}
	return (max_position);
}

void	push_chunks(t_no **a, t_no **b, int chunk_size, t_bench *bench)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			push_b(a, b, bench);
			rotate_b(b, bench);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			push_b(a, b, bench);
			i++;
		}
		else
			rotate_a(a, bench);
	}
}

void	push_back_to_a(t_no **a, t_no **b, t_bench *bench)
{
	int	position;
	int	size;

	while (*b)
	{
		position = get_max_index_position(*b);
		size = len_stack(*b);
		if (position <= size / 2)
		{
			while (position-- > 0)
				rotate_b(b, bench);
		}
		else
		{
			while (position < size)
			{
				reverse_b(b, bench);
				position++;
			}
		}
		push_a(a, b, bench);
	}
}

int	get_chunk_size(int size)
{
	int	chunk_size;

	chunk_size = raiz(size);
	if (chunk_size < 1)
		chunk_size = 1;
	return (chunk_size);
}
