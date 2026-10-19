/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:29:56 by obdintal          #+#    #+#             */
/*   Updated: 2026/09/01 15:50:01 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(va_list *arg, int *count)
{
	ft_putchar(va_arg(*arg, int), 1, count);
}

void	ft_print_s(va_list *arg, int *count)
{
	char	*str;

	str = va_arg(*arg, char *);
	if (!str)
		ft_putstr("(null)", count);
	ft_putstr(str, count);
}

void	ft_print_percent(va_list *arg, int *count)
{
	(void)arg;
	ft_putchar('%', 1, count);
}

void	ft_print_invalid(const char **format, int *count)
{
	ft_putchar('%', 1, count);
	ft_putchar(**format, 1, count);
	if (*(*format + 1) == '%' && *(*format + 2) == '\0')
	{
		(*format)++;
		ft_putchar('%', 1, count);
	}
}
