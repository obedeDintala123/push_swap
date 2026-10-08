/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:34:16 by obdintal          #+#    #+#             */
/*   Updated: 2026/09/05 11:17:47 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd, int *count)
{
	write(fd, &c, 1);
	(*count)++;
}

void	ft_putstr_fd(char *s, int *count)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, 1, count);
		s++;
	}
}

void	ft_putnbr_fd(int n, int fd, int *count)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd, count);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd, count);
	ft_putchar_fd((nbr % 10) + '0', fd, count);
}

void	ft_puthex_fd(unsigned int n, int is_uppercase, int fd, int *count)
{
	if (n >= 16)
		ft_puthex_fd((n / 16), is_uppercase, fd, count);
	if (is_uppercase)
		ft_putchar_fd("0123456789ABCDEF"[n % 16], fd, count);
	else
		ft_putchar_fd("0123456789abcdef"[n % 16], fd, count);
}

void	ft_get_specifier(const char **format, va_list *args, int *count)
{
	if (**format == 'd' || **format == 'i')
		ft_print_d(args, count);
	else if (**format == 'u')
		ft_print_u(args, count);
	else if (**format == 'p')
		ft_print_p(args, count);
	else if (**format == 'c')
		ft_print_c(args, count);
	else if (**format == 's')
		ft_print_s(args, count);
	else if (**format == 'x')
		ft_print_x(args, count);
	else if (**format == 'X')
		ft_print_x_upper(args, count);
	else if (**format == '%')
		ft_print_percent(args, count);
	else
		ft_print_invalid(format, count);
}
