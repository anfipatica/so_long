/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:25:53 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/05/06 22:31:05 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *string)
{
	int	i;
	
	if (!string)
	{
		return (0);
	}
	i = 0;
	while (string[i])
	{
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	printf("Nuestra función devuelve: %lu\n", ft_strlen("holaaaa"));
// 	printf("La función original devuele: %lu", strlen("holaaaa"));
// 	return(0);
// }