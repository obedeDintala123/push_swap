/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:33:05 by obdintal          #+#    #+#             */
/*   Updated: 2026/09/01 14:34:09 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_u(unsigned int n, int fd, int *count)
{
	if (n >= 10)
		ft_putnbr_u(n / 10, fd, count);
	ft_putchar((n % 10) + '0', fd, count);
}

void	ft_print_d(va_list *arg, int *count)
{
	ft_putnbr(va_arg(*arg, int), 1, count);
}

void	ft_print_u(va_list *arg, int *count)
{
	ft_putnbr_u(va_arg(*arg, unsigned int), 1, count);
}
