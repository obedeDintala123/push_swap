/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:14:09 by obdintal          #+#    #+#             */
/*   Updated: 2026/10/19 20:11:18 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_value(t_no **stack, int value)
{
	t_no	*node;
	t_no	*last;

	node = malloc(sizeof(t_no));
	if (!node)
		return (0);
	node->value = value;
	node->next = NULL;
	if (!*stack)
	{
		*stack = node;
		return (1);
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = node;
	return (1);
}

void	ft_free_stack(t_no *str)
{
	t_no	*next;

	while (str)
	{
		next = str->next;
		free(str);
		str = next;
	}
}