/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:41:28 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/05/06 23:44:42 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			len_s1;
	size_t			len_s2;
	unsigned int	i;
	unsigned int	j;
	char			*s3;

	if (!s1 && !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	s3 = ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	if (!s3)
		return (0);
	while (i < len_s1 || i < len_s2)
	{
		if (i < len_s1)
			s3[j] = s1[i];
		if (i < len_s2)
			s3[j + len_s1] = s2[i];
		j++;
		i++;
	}
	return (s3);
}
// int	main (void)
// {
// 	char	s1[] = "abc";
// 	char	s2[] = "";

// 	printf("%s\n", ft_strjoin(s1,s2));
// 	return (0);
// }