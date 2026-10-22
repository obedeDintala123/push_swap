/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:23:48 by obdintal          #+#    #+#             */
/*   Updated: 2026/10/19 21:00:31 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_stack(t_no *stack)
{
	ft_printf("Stack A (top -> bottom): ");
	while (stack)
	{
		ft_printf("%d", stack->value);
		if (stack->next)
			ft_printf(" -> ");
		stack = stack->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_no	*stack_a;
	char	**values;
	int		i;
	int		j;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		values = ft_get_nbr(argv[i]);
		if (!values)
		{
			ft_free_stack(stack_a);
			return (ft_putstr_fd("Error\n", 2), 1);
		}
		j = 0;
		while (values[j])
		{
			if (!ft_push_value(&stack_a, ft_atoi(values[j])))
			{
				ft_free_array(values);
				ft_free_stack(stack_a);
				return (ft_putstr_fd("Error\n", 2), 1);
			}
			j++;
		}
		ft_free_array(values);
		i++;
	}
	ft_print_stack(stack_a);
	ft_chose_method(stack_a);
	ft_free_stack(stack_a);
	return (0);
}
