/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:50:54 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/09/26 15:17:28 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == ((char) c))
			return (&((char *)s)[i]);
		i--;
	}
	return (NULL);
}

// int	main (void)
// {
// 	char	s[] = "teste";
// 	int		c = 'e';
// 	printf("%s\n", strrchr(s,'t' + 256));
// 	printf("%s\n", ft_strrchr(s,'t' + 256));

// 	return (0);
// }