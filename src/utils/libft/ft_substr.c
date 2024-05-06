/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:50:04 by marvin            #+#    #+#             */
/*   Updated: 2023/09/27 20:50:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s1, unsigned int start, size_t len)
{
	char			*s2;
	size_t			total_len;
	unsigned int	i;

	if (start > ft_strlen(s1) || !s1)
		return (ft_strdup(""));
	total_len = ft_strlen(s1) - start;
	i = 0;
	if (total_len > len)
		total_len = len;
	s2 = ft_calloc((total_len + 1), sizeof(char));
	if (s2 != NULL)
	{
		while (i < total_len)
		{
			s2[i] = s1[start + i];
			i++;
		}
	}
	return (s2);
}
