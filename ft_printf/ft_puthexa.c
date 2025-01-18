/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:09:42 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/27 19:38:35 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int nb, char c)
{
	int		re_value;
	char	*base_l;
	char	*base_u;

	re_value = 0;
	base_l = "0123456789abcdef";
	base_u = "0123456789ABCDEF";
	if (nb >= 16)
		re_value += ft_puthexa(nb / 16, c);
	if (c == 'x')
		re_value += ft_putchr(base_l[nb % 16]);
	else if (c == 'X')
		re_value += ft_putchr(base_u[nb % 16]);
	return (re_value);
}
