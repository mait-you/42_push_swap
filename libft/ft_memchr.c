/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:45:37 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/14 10:33:34 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ss;
	unsigned char		cc;

	cc = (unsigned char)c;
	ss = (const unsigned char *)s;
	while (n--)
	{
		if (*ss == cc)
			return ((void *)s);
		s++;
		ss++;
	}
	return (NULL);
}
