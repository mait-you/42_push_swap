/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:18:45 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/15 09:07:53 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	if (dstsize < src_len + 1)
	{
		ft_memcpy(dst, src, dstsize - 1);
		*(dst + dstsize - 1) = 0;
	}
	else
		ft_memcpy(dst, src, src_len + 1);
	return (src_len);
}
