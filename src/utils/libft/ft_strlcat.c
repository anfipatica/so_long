/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:06:40 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/09/26 15:10:36 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	s;
	size_t	d;
	size_t	size_s;
	size_t	size_d;

	size_s = ft_strlen(src);
	size_d = ft_strlen(dst);
	if ((!dst && n == 0) || n <= size_d)
		return (size_s + n);
	s = 0;
	d = size_d;
	while (src[s] && d + 1 < n)
	{
		dst[d] = src[s];
		d++;
		s++;
	}
	dst[d] = '\0';
	return (size_d + size_s);
}

// int	main(void)
// {
// 	char	s1[11] = "a";
// 	char	s2[] = "lorem";
// 	char	s3[11] = "a";
// 	char	s4[] = "lorem";
// 	int		n = 15;

// 	//printf("s1 original: %s\ns2 original: %s\n",  s1, s2);
// 	//printf("strlcpy devuelve: %zu\n", strlcat(s1, s2, n));
// 	//printf("s1: %s\ns2: %s\n\n",  s1, s2);

// 	printf("s3 original: %s\ns4 original: %s\n",  s3, s4);
// 	printf("ft_strlcat devuelve: %zu\n", ft_strlcat(s3, s4, n));
// 	printf("s3: %s\ns4: %s\n\n",  s3, s4);

// 	return(0);
// }