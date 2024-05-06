/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:50:31 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/09/26 15:18:57 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ' ');
	return (c);
}

// int	main (void)
// {
// 	char	c = 'p';
// 	printf("%c\n", tolower(c));
// 	printf("%c\n", ft_tolower(c));

// 	return (0);
// }
