/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:12:59 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/17 22:00:59 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str, int *error)
{
	int				i;
	long			r;
	int				s;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		*error = 0;
		r = r * 10 + (str[i] - '0');
		i++;
	}
	if ((str[i] && (str[i] < '0' || str[i] > '9')) || \
		(s * r) > INT_MAX || (s * r) < INT_MIN)
		*error = 1;
	return (s * r);
}
