/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:03:48 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/10 18:19:32 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim(char const *s1, char const *set)
{
	while (*set)
	{
		if (*s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		ptr_len;
	int		s_len;
	int		i;

	if (!set || !s1)
		return (NULL);
	while (trim(s1, set))
		s1++;
	s_len = ft_strlen(s1);
	i = 0;
	while (trim(((s1 + s_len) - 1 - i), set))
		i++;
	ptr_len = s_len - i;
	return (ft_substr(s1, 0, ptr_len));
}
