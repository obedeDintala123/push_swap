/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 15:01:25 by obdintal          #+#    #+#             */
/*   Updated: 2026/08/14 13:33:19 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	find_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j] && set[j] != s1[i])
			j++;
		if (!set[j])
			return (i);
		i++;
	}
	return (i);
}

static	int	find_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j] && set[j] != s1[i])
			j++;
		if (!set[j])
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*new_s;

	if (!s1 || !set)
		return (NULL);
	start = find_start(s1, set);
	end = find_end(s1, set);
	i = 0;
	if (start > end)
	{
		new_s = malloc(1);
		if (!new_s)
			return (NULL);
		new_s[0] = '\0';
		return (new_s);
	}
	new_s = malloc(sizeof(char) * (end - start + 2));
	if (!new_s)
		return (NULL);
	while (start <= end)
		new_s[i++] = s1[start++];
	new_s[i] = '\0';
	return (new_s);
}
