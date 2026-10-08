/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:33:05 by obdintal          #+#    #+#             */
/*   Updated: 2026/09/05 11:34:49 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_u_fd(unsigned int n, int fd, int *count)
{
	if (n >= 10)
		ft_putnbr_u_fd(n / 10, fd, count);
	ft_putchar_fd((n % 10) + '0', fd, count);
}

void	ft_print_d(va_list *arg, int *count)
{
	ft_putnbr_fd(va_arg(*arg, int), 1, count);
}

void	ft_print_u(va_list *arg, int *count)
{
	ft_putnbr_u_fd(va_arg(*arg, unsigned int), 1, count);
}
