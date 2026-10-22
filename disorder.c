/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:55:06 by obdintal          #+#    #+#             */
/*   Updated: 2026/10/19 19:30:49 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static float	ft_compute_disorder(t_no *pilha_a)
{
	int		mistakes;
	int		total_pairs;
	t_no	*i;
	t_no	*j;

	total_pairs = 0;
	mistakes = 0;
	i = pilha_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if ((i->value) > (j->value))
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((float)mistakes / total_pairs);
}

void	ft_chose_method(t_no *pilha_a)
{
	float	disorder;

	disorder = ft_compute_disorder(pilha_a);
	if (disorder < 0.2)
		printf("%s - %.1f\n", "simple", disorder);
	else if (disorder >= 0.2 && disorder < 0.5)
		printf("%s - %.1f\n", "medium", disorder);
	else if (disorder >= 0.5)
		printf("%s - %.1f\n", "complex", disorder);
	else
		printf("%.1f\n", disorder);
}
