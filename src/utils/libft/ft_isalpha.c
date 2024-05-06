/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:24:48 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/10/22 13:50:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <ctype.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

//int	main(void)
//{
//printf("Nuestra función devuelve: %d\n", ft_isalpha('Q'));
//printf("La función original devuele: %d\n", isalpha('Q'));
//return(0);
//}