/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 16:14:04 by obdintal          #+#    #+#             */
/*   Updated: 2026/08/14 11:29:18 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	if (!dest || !src)
		return (NULL);
	p1 = (unsigned char *)src;
	p2 = (unsigned char *)dest;
	if (p2 > p1)
		while (n--)
			p2[n] = p1[n];
	else
	{
		i = 0;
		while (i < n)
		{
			p2[i] = p1[i];
			i++;
		}
	}
	return (dest);
}
