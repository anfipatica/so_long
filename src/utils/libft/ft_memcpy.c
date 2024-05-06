/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:12:00 by marvin            #+#    #+#             */
/*   Updated: 2023/09/18 19:12:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

// int	main (void)
// {
// 	char	src1[] = "Hello!";
// 	//char	dest1[] = "abcdef";
// 	char	src2[] = "Hello!";
// 	//char	dest2[] = "abcdef";

// 	printf("%s\n", src1);
// 	memcpy(src1 + 2, src1, 4);
// 	printf("%s\n", src1);

// 	printf("\n%s\n", src2);
// 	ft_memcpy(src2 + 2, src2, 4);
// 	printf("%s\n", src2);
// 	return (0);
// }