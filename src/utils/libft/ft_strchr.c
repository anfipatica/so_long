/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:01:10 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/10/20 18:40:33 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s[i] == ((char)c))
		return (&((char *)s)[i]);
	while (s[i])
	{
		if (s[i + 1] == ((char)c))
			return (&((char *)s)[i + 1]);
		i++;
	}
	return (NULL);
}

// int	main (void)
// {
// 	char	s[] = "teste";
// 	int		c = '\0';
// 	printf("%s\n", strchr(s,c));
// 	printf("%s\n", ft_strchr(s,c));

// 	return (0);
// }