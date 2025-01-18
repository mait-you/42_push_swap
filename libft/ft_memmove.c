/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:33:14 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/14 10:32:35 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr;

	if (src == dst)
		return (dst);
	ptr = (char *)dst;
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			*(ptr + len) = *(const char *)(src + len);
	}
	return (dst);
}
