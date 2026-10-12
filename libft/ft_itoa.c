/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:15:17 by obdintal          #+#    #+#             */
/*   Updated: 2026/08/14 14:29:54 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_digits(long n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	if (n >= 0 && n <= 9)
		size++;
	else
		size += 1 + count_digits(n / 10);
	return (size);
}

static	void	set_digits(char *str, long n, int i)
{
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n >= 0 && n <= 9)
		str[i] = n + '0';
	else
	{
		str[i] = (n % 10) + '0';
		set_digits(str, (n / 10), (i - 1));
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;

	digits = count_digits((long)n);
	str = malloc(sizeof(char) * digits + 1);
	if (!str)
		return (NULL);
	set_digits(str, (long)n, digits - 1);
	str[digits] = '\0';
	return (str);
}
