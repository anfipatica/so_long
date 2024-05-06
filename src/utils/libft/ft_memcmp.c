/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:23:06 by marvin            #+#    #+#             */
/*   Updated: 2023/09/20 22:23:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = ((unsigned char *)s1);
	p2 = ((unsigned char *)s2);
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}

// int	main (void)
// {
// 	char	s1[] = "höla\0\0tonto";
// 	char	s2[] = "höla\0petete";
// 	size_t	n = 10;

// 	printf("%d\n", memcmp(s1, s2, n));
// 	printf("%d\n", ft_memcmp(s1, s2, n));
// 	return (0);
// }