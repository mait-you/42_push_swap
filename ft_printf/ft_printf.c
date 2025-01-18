/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:21:40 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/09 16:23:10 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_format(const char f, va_list args)
{
	int		re_value;

	re_value = 0;
	if (f == '%')
		re_value = ft_putchr(f);
	else if (f == 'c')
		re_value = ft_putchr(va_arg(args, int));
	else if (f == 's')
		re_value = ft_putstr(va_arg(args, char *));
	else if (f == 'p')
	{
		re_value = ft_putstr("0x");
		re_value += ft_putadress(va_arg(args, unsigned long));
	}
	else if (f == 'd' || f == 'i')
		re_value = ft_putnbr(va_arg(args, int));
	else if (f == 'u')
		re_value = ft_putunbr(va_arg(args, unsigned int));
	else if (f == 'x' || f == 'X')
		re_value = ft_puthexa(va_arg(args, unsigned int), f);
	else
		re_value = ft_putchr(f);
	return (re_value);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		re_value;

	re_value = write(1, "", 0);
	if (re_value == -1)
		return (re_value);
	va_start(args, format);
	re_value = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
			re_value += find_format(*(++format), args);
		else if (*format && *format != '%')
			re_value += ft_putchr(*format);
		format++;
	}
	va_end(args);
	return (re_value);
}
