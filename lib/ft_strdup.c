/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:38:46 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/23 06:23:59 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	s1_len;
	char	*ptr;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	str = (char *)malloc(s1_len + 1);
	if (!str)
		return (NULL);
	ptr = str;
	while (*s1)
	{
		*ptr = *s1;
		ptr++;
		s1++;
	}
	*ptr = '\0';
	return (str);
}
