/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:29:56 by obdintal          #+#    #+#             */
/*   Updated: 2026/09/19 20:55:05 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(va_list *arg, int *count)
{
	ft_putchar_fd(va_arg(*arg, int), 1, count);
}

void	ft_print_s(va_list *arg, int *count)
{
	char	*str;

	str = va_arg(*arg, char *);
	if (!str)
		ft_putstr_fd("(null)", count);
	ft_putstr_fd(str, count);
}

void	ft_print_percent(va_list *arg, int *count)
{
	(void)arg;
	ft_putchar_fd('%', 1, count);
}

void	ft_print_invalid(const char **format, int *count)
{
	ft_putchar_fd('%', 1, count);
	ft_putchar_fd(**format, 1, count);
	if (*(*format + 1) == '%' && *(*format + 2) == '\0')
	{
		(*format)++;
		ft_putchar_fd('%', 1, count);
	}
}
