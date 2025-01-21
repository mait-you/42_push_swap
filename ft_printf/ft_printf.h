/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:21:35 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/19 10:10:34 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

# define SPECIFIERS	"cspdiuxX%"
# define X_SPECIFIERS	"0123456789#-+ "

int			ft_printf(const char *format, ...);
int			ft_putchr(char c);
int			ft_putstr(char *s);
int			ft_putadress(unsigned long nb);
int			ft_putnbr(int nb);
int			ft_putunbr(unsigned int nb);
int			ft_puthexa(unsigned int nb, char c);

#endif
