/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:01:34 by marvin            #+#    #+#             */
/*   Updated: 2023/09/18 16:01:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *string, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)string)[i] = '\0';
		i++;
	}
}

// int	main (void)
// {
// 	char	string[7] = "patata";
// 	char	string2[7] = "patata";
// 	printf("%s\n",string);
// 	bzero(string, 7);
// 	printf("%s\n",string);
// 	printf("%s\n",string2);
// 	ft_bzero(string2, 7);
// 	printf("%s\n",string2);
// 	return (0);
// }
