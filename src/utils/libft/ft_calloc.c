/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:37:38 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/04/26 16:27:14 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*str;

	str = (malloc(nitems * size));
	if (str == 0)
	{
		return (NULL);
	}
	ft_bzero(str, (nitems * size));
	return (str);
}

// int main() {
//     int *arr;
//     int n = 20;

// 	printf("Ahora probamos el calloc original:\n");
// 	printf("%d\n",calloc(n,0));
// 	printf("Y ahora probamos el nuestro:\n");
// 	printf("%d\n", ft_calloc(n, 0));

// 	return 0; // Salir sin errores
// }
