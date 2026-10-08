/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:55:52 by obdintal          #+#    #+#             */
/*   Updated: 2026/08/13 12:16:22 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	char	*new_s;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	new_s = malloc(sizeof(char) * (size + 1));
	if (!new_s)
		return (NULL);
	new_s[size] = '\0';
	while (size--)
		new_s[size] = f(size, s[size]);
	return (new_s);
}
