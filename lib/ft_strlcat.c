/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:17:10 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/15 09:06:39 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	size_t			remaining;

	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	remaining = dstsize - dst_len - 1;
	if (remaining < src_len)
	{
		ft_memcpy(dst + dst_len, src, remaining);
		*(dst + dst_len + remaining) = '\0';
	}
	else
		ft_memcpy(dst + dst_len, src, src_len + 1);
	return (dst_len + src_len);
}
