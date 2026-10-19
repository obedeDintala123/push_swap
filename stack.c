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

t_no	*ft_create_stack(char **values)
{
	t_no	*head;
	t_no	*node;
	int		i;
	int		size;

	head = NULL;
	i = 0;
	size = sizeof(values) / sizeof(values[0]);
	while (i < size)
	{
		node = malloc(sizeof(t_no));
		if (!node)
			return (NULL);
		node->value = ft_atoi(values[i]);
		node->next = head;
		head = node;
		i++;
	}
	return (head);
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