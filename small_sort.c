/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 00:00:00 by obdintal          #+#    #+#             */
/*   Updated: 2026/10/27 00:00:00 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_no *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

static int	find_position(t_no *stack, int index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == index)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}

static void	bring_up(t_no **stack, int position, t_bench *bench)
{
	int	size;

	size = len_stack(*stack);
	if (position <= size / 2)
	{
		while (position-- > 0)
			rotate_a(stack, bench);
	}
	else
	{
		while (position++ < size)
			reverse_a(stack, bench);
	}
}

static void	sort_three(t_no **stack, t_bench *bench)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (a > b && b < c && a < c)
		sa(stack, bench);
	else if (a > b && b > c)
		(sa(stack, bench), reverse_a(stack, bench));
	else if (a > b && b < c && a > c)
		rotate_a(stack, bench);
	else if (a < b && b > c && a < c)
		(sa(stack, bench), rotate_a(stack, bench));
	else if (a < b && b > c && a > c)
		reverse_a(stack, bench);
}

void	sort_small(t_no **stack_a, t_no **stack_b, t_bench *bench)
{
	int	index;
	int	position;

	while (len_stack(*stack_a) > 3)
	{
		index = find_min_index(*stack_a);
		position = find_position(*stack_a, index);
		bring_up(stack_a, position, bench);
		push_b(stack_a, stack_b, bench);
	}
	if (len_stack(*stack_a) == 2 && (*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, bench);
	else if (len_stack(*stack_a) == 3)
		sort_three(stack_a, bench);
	while (*stack_b)
		push_a(stack_a, stack_b, bench);
}
