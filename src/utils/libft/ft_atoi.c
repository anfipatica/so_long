/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:09:52 by marvin            #+#    #+#             */
/*   Updated: 2023/09/25 22:09:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 0;
	j = 1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+' )
	{
		if (s[i] == '-')
			j = j * -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = (n * 10) + (s[i] - '0');
		i++;
	}
	return (n * j);
}

// int    main (void)
// {
// 	char n[] = "-4886";
// 	printf("atoi: %d\n",atoi(n));
// 	printf("ft_atoi: %d\n", ft_atoi(n));
// 	return(0);
// }