/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:24:44 by obdintal          #+#    #+#             */
/*   Updated: 2026/10/19 11:24:47 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free_array(char **array)
{
    int i;

    if (!array)
        return ;
    i = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}

int	ft_iswhitespace(char *str)
{
	while (*str)
	{
		if (!(*str == 32 || (*str >= 9 && *str <= 13)))
			return (1);
		str++;
	}
	return (0);
}

int ft_has_space(char *str)
{
    while (*str)
    {
        if (*str == ' ')
            return (1);
        str++;
    }
    return (0);
}

int ft_count_opt(char **argv)
{
    int i;
    int count;

    i = 1;
    count = 0;
    while (argv[i])
    {
        if (argv[i][0] == '-' && ft_isalpha(argv[i][1]))
            count++;
        else if (argv[i][0] == '-' && argv[i][1] == '-' && ft_isalpha(argv[i][2]))
            count++;
        i++;
    }
    return (count);
}

