/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selec_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalata <cpalata@student.42luanda.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 08:59:04 by cpalata           #+#    #+#             */
/*   Updated: 2026/10/19 20:12:33 by cpalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sign_index(t_no *pilha)
{
	t_no	corrent;
	t_no	other;
	int		count;

	corrent = pilha;
	while (corrent)
	{
		count = 0;
		other = pilha;
		while (other)
		{
			if (corrent->value < other->value)
				count++;
			other = other->next;
		}
		corrent->index = count;
		corrent = count->next;
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

static int find_position(t_no *pilha, int index)
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
