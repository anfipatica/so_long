/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:25:03 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/09/26 14:09:23 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <ctype.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("Nuestra función devuelve: %d\n", ft_isascii(20));
// 	printf("La función original devuele: %d", isascii(20));
// 	return(0);
// }