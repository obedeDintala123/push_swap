/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 10:59:44 by obdintal          #+#    #+#             */
/*   Updated: 2026/10/19 11:23:32 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isvalid_input(int argc, char **argv)
{
	if (argc < 2)
		return (1);

	if (ft_count_opt(argv) > 0)
	{
		if (ft_validate_opt(argv) && ft_has_nbr(argv) && ft_validate_nbr(argv))
			return (0);
	}
	else if (ft_validate_nbr(argv))
		return (0);

	ft_putstr_fd("Error\n", 2);
	return (0);
}