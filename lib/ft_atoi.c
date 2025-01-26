/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:12:59 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/26 09:42:54 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str, int *error)
{
	int		i;
	long	r;
	int		sign;

	i = 0;
	r = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		*error = 0;
		r = r * 10 + (str[i] - '0');
		if ((r * sign > INT_MAX) || (r * sign < INT_MIN))
			return (*error = 1);
		i++;
	}
	if ((str[i] && (str[i] < '0' || str[i] > '9')))
		return (*error = 1);
	return ((int)(sign * r));
}
