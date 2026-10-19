/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:26:24 by obdintal          #+#    #+#             */
/*   Updated: 2026/10/19 20:03:49 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_flag(char *str)
{
	return ((str[0] == '-' && ft_isalpha(str[1]))
		|| (str[0] == '-' && str[1] == '-' && ft_isalpha(str[2])));
}

int	ft_is_opt(char *str, char *opt)
{
	return (!ft_strncmp(str, opt, ft_strlen(opt) + 1));
}

int	ft_is_mode(char *str)
{
	return (ft_is_opt(str, "--simple") || ft_is_opt(str, "--medium")
		|| ft_is_opt(str, "--complex") || ft_is_opt(str, "--adaptive"));
}

int	ft_count_values(char **values, int size)
{
	int	i;

	i = 0;
	while (i < size && values[i])
		i++;
	return (i);
}