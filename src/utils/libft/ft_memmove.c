/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:21:29 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/10/22 14:10:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_ptr;
	char	*src_ptr;

	i = 0;
	dest_ptr = ((char *)dest);
	src_ptr = ((char *)src);
	if (!dest_ptr && !src_ptr)
		return (NULL);
	if (dest_ptr < src_ptr)
	{
		while (i < n)
		{
			dest_ptr[i] = src_ptr[i];
			i++;
		}
	}
	if (dest_ptr > src_ptr)
	{
		while (--n + 1 > 0)
			dest_ptr[n] = src_ptr[n];
	}
	return (dest_ptr);
}

// int	main (void)
// {
// 	char	src1[] = "Hello!";
// 	char	src2[] = "Hello!";

// 	printf("%s\n", src1);
// 	memmove(src1 + 2, src1, 5);
// 	printf("%s\n", src1);

// 	printf("%s\n", src2);
// 	ft_memmove(src2 + 2, src2, 5);
// 	printf("%s\n", src2);

// 	return (0);
// }