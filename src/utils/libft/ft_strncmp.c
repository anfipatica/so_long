/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:57 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/10/04 20:58:05 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while ((s1[i] || s2[i]) && i < n)
		{
			if (s1[i] != s2[i])
				return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
			i++;
		}
	}
	return (0);
}

// int	main (void)
// {
// 	char	s1[] = "hellozz";
// 	char	s2[] = "z";
// 	int		n = 10;
// 	printf("%d\n", strncmp(s1,s2,n));
// 	printf("%d\n", ft_strncmp(s1,s2,n));

// 	return (0);
// }