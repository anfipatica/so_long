/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:30:24 by marvin            #+#    #+#             */
/*   Updated: 2023/09/30 14:30:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*write_chars(int n, int len, char *str)
{
	int	n2;

	n2 = n;
	if (n2 == -2147483648)
		n--;
	while (len > 0)
	{
		str[--len] = (n % 10) + 48;
		n = n / 10;
	}
	if (n2 == -2147483648)
		str[10] = '8';
	return (str);
}

char	check_sign(int n)
{
	if (n < 0)
		return ('-');
	return ('+');
}

size_t	get_len(int n)
{
	unsigned int	len;

	len = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*str;
	char			sign;

	len = get_len(n);
	sign = check_sign(n);
	if (sign == '-' && len != 0)
		str = ft_calloc((len + 2), sizeof(char));
	else if (sign == '+' && len != 0)
		str = ft_calloc((len + 1), sizeof(char));
	else
		return (ft_strdup(""));
	if (str != NULL)
	{
		if (sign == '-')
		{
			str = write_chars(n * -1, len + 1, str);
			str[0] = '-';
		}
		else
			str = write_chars(n, len, str);
		return (str);
	}
	return (0);
}

// int	main(void)
// {
// 	printf("ft_itoa devuelve: %s\n", ft_itoa(-2147483648));
// 	return (0);
// }