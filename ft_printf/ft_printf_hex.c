/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:31:10 by obdintal          #+#    #+#             */
/*   Updated: 2026/09/01 14:32:49 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex_p(uintptr_t n, int *count)
{
	if (n >= 16)
		ft_puthex_p((n / 16), count);
	ft_putchar("0123456789abcdef"[n % 16], 1, count);
}

void	ft_print_p(va_list *arg, int *count)
{
	void		*ptr;
	uintptr_t	address;

	ptr = va_arg(*arg, void *);
	address = (uintptr_t)ptr;
	if (!ptr)
		ft_putstr("(nil)", count);
	else
	{
		ft_putstr("0x", count);
		ft_puthex_p(address, count);
	}
}

void	ft_print_x(va_list *arg, int *count)
{
	unsigned int	n;

	n = va_arg(*arg, unsigned int);
	ft_puthex(n, 0, 1, count);
}

void	ft_print_x_upper(va_list *arg, int *count)
{
	unsigned int	n;

	n = va_arg(*arg, unsigned int);
	ft_puthex(n, 1, 1, count);
}
