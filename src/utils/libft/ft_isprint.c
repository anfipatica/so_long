/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:25:39 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/09/26 14:10:12 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <ctype.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("Nuestra función devuelve: %d\n", ft_isprint(223));
// 	printf("La función original devuele: %d", isprint(223));
// 	return(0);
// }