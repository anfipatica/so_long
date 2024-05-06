/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:24:34 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/10/22 13:51:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isalnum( int c )
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("Nuestra función devuelve: %d\n", ft_isalnum('-'));
// 	printf("La función original devuele: %d", isalnum('-'));
// 	return(0);
// }