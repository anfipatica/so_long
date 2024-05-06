/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:08:01 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/09/26 15:18:34 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s2[i])
		return (((char *) s1));
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < n)
		{
			if (s2[j + 1] == '\0')
				return (&((char *)s1)[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

// int main() {
// 	const char texto[] = "lorem ipsum dolor sit amet";
// 	const char subcadena[] = "dolor";
// 	size_t longitud = 15; // Máximo de caracteres a buscar

// 	//printf("%d\n",strnstr(texto, subcadena, longitud));
// 	printf("%s\n",ft_strnstr(texto, subcadena, longitud));

// 	return 0;
// }
