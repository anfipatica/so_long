/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:09:56 by marvin            #+#    #+#             */
/*   Updated: 2023/09/20 15:09:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = ((unsigned char *)s);
	while (n > 0)
	{
		if (*p == ((unsigned char) c))
			return (p);
		p++;
		n--;
	}
	return (NULL);
}

// int	main (void)
// {
// 	char	s[] = "Espana";
// 	int		c = 'n';
// 	size_t	n = 5;

// 	//printf("%p\n", memchr(((void *)0), '\0', 0x20));
// 	printf("%p\n", ft_memchr(((void *)0), '\0', 0x20));
// 	return (0);
// }
