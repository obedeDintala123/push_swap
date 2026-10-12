/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 16:14:33 by obdintal          #+#    #+#             */
/*   Updated: 2026/08/22 18:08:13 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	size = ft_strlen(s);
	while (i--)
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	if (s[size] == (char)c)
		return ((char *)&s[size]);
	return (NULL);
}
