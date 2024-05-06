/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:25:28 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/09/26 14:09:55 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <ctype.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("Nuestra función devuelve: %d\n", ft_isdigit('Q'));
// 	printf("La función original devuele: %d", isdigit('Q'));
// 	return(0);
// }