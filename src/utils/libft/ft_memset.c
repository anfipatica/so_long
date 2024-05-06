/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:50:02 by marvin            #+#    #+#             */
/*   Updated: 2023/10/20 17:39:52 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = c;
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char	str1[50] = "This is string.h library function";
// 	char	str2[50] = "This is string.h library function";

// 	printf("%p\n", ft_memset(str1,'$',15));

// 	printf("%p\n", memset(str1,'$',15));
// 	return(0);
// }