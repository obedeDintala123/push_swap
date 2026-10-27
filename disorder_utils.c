/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 00:00:00 by obdintal          #+#    #+#             */
/*   Updated: 2026/10/27 00:00:00 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dis	compute_disorder(t_no *stack)
{
	t_dis	result;
	t_no	*i;
	t_no	*j;

	result.mistakes = 0;
	result.total_pairs = 0;
	result.ratio = 0;
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			result.total_pairs++;
			if (i->value > j->value)
				result.mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (result.total_pairs > 0)
		result.ratio = (float)result.mistakes / result.total_pairs;
	return (result);
}
