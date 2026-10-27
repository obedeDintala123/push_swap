/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:23:48 by obdintal          #+#    #+#             */
/*   Updated: 2026/10/27 00:00:00 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	build_stack(t_no **stack_a, int argc, char **argv)
{
	char	**values;
	int		i;
	int		j;

	i = ft_first_nbr_idx(argv);
	while (i < argc)
	{
		values = ft_get_nbr(argv[i++]);
		if (!values)
			return (0);
		j = 0;
		while (values[j])
		{
			if (!ft_push_value(stack_a, ft_atoi(values[j++])))
				return (ft_free_array(values), 0);
		}
		ft_free_array(values);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_no	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (!ft_validate_opt(argv) || !ft_has_nbr(argv) || !ft_validate_nbr(argv))
		return (ft_putstr_fd("Error\n", 2), 1);
	if (!build_stack(&stack_a, argc, argv))
	{
		ft_free_stack(stack_a);
		return (ft_putstr_fd("Error\n", 2), 1);
	}
	ft_chose_method(&stack_a, argv);
	ft_free_stack(stack_a);
	return (0);
}
