/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:27:19 by obdintal          #+#    #+#             */
/*   Updated: 2026/09/05 11:17:37 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);

void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putnbr_fd(int n, int fd, int *count);
void	ft_putstr_fd(char *s, int *count);
void	ft_puthex_fd(unsigned int n, int is_uppercase, int fd, int *count);

void	ft_print_d(va_list *arg, int *count);
void	ft_print_u(va_list *arg, int *count);
void	ft_print_c(va_list *arg, int *count);
void	ft_print_s(va_list *arg, int *count);
void	ft_print_p(va_list *arg, int *count);
void	ft_print_x(va_list *arg, int *count);
void	ft_print_x_upper(va_list *arg, int *count);
void	ft_print_percent(va_list *arg, int *count);
void	ft_print_invalid(const char **format, int *count);

void	ft_get_specifier(const char **format, va_list *args, int *count);

#endif