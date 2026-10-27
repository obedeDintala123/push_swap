/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selec_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalata <cpalata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 08:59:04 by cpalata           #+#    #+#             */
/*   Updated: 2026/10/23 20:41:50 by cpalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sign_index(t_no *pilha)
{
	t_no	*corrent;
	t_no	*other;
	int		count;

	corrent = pilha;
	while (corrent)
	{
		count = 0;
		other = pilha;
		while (other)
		{
			if (corrent->value > other->value)
				count++;
			other = other->next;
		}
		corrent->index = count;
		corrent = corrent->next;
	}
}

static int	find_min_index(t_no *pilha)
{
	int	min;

	min = pilha->index;
	while (pilha)
	{
		if (pilha->index < min)
			min = pilha->index;
		pilha = pilha->next;
	}
	return (min);
}

static int	find_position(t_no *pilha, int index)
{
	int	position;

	position = 0;
	while (pilha)
	{
		if (pilha->index == index)
			return (position);
		position++;
		pilha = pilha->next;
	}
	return (-1);
}

static void	bring_up(t_no **pilha, int position, t_bench *bench)
{
	int	size;
	int	rotetion;

	size = len_stack(*pilha);
	if (position <= size / 2)
	{
		while (position > 0)
		{
			rotate_a(pilha, bench);
			position--;
		}
	}
	else
	{
		rotetion = size - position;
		while (rotetion > 0)
		{
			reverse_a(pilha, bench);
			rotetion--;
		}
	}
}

void	select_sort(t_no **pilha_a, t_no **pilha_b, t_bench *bench)
{
	int	indice;
	int	position;

	if (!*pilha_a)
		return ;
	while (*pilha_a)
	{
		indice = find_min_index(*pilha_a);
		position = find_position(*pilha_a, indice);
		bring_up(pilha_a, position, bench);
		push_b(pilha_a, pilha_b, bench);
	}
	while (*pilha_b)
		push_a(pilha_a, pilha_b, bench);
}
