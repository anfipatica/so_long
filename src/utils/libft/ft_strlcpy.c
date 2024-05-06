/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:47:43 by marvin            #+#    #+#             */
/*   Updated: 2023/10/22 14:13:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while (src[i] && i < n - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	char	s1[10] = "";
// 	char	s2[] = "abcdefghij";
// 	char	s3[10] = "";
// 	char	s4[] = "abcdefghij";
// 	int		n = 10;

// 	printf("s3 original: %s\ns4 original: %s\n",  s3, s4);
// 	printf("ft_strlcpy devuelve: %zu\n", ft_strlcpy(s3,s4, n));
// 	printf("s3: %s\ns4: %s\n\n",  s3, s4);

// 	printf("s1 original: %s\ns2 original: %s\n",  s1, s2);
// 	printf("strlcpy devuelve: %zu\n", strlcpy(s1,s2, n));
// 	printf("s1: %s\ns2: %s\n\n",  s1, s2);

// 	return(0);
// }
