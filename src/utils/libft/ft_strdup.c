/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:51:52 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/10/20 17:49:28 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;
	int		j;

	i = ft_strlen(s1);
	s2 = malloc((i + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	j = 0;
	while (i >= j)
	{
		s2[j] = s1[j];
		j++;
	}
	return (s2);
}

// int	main (void)
// {
// 	char	s1[] = "\0";
// 	printf("%s\n", strdup(s1));
// 	printf("%s\n", ft_strdup(s1));
// 	return (0);
// }