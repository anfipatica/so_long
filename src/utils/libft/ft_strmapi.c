/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 10:46:31 by marvin            #+#    #+#             */
/*   Updated: 2023/10/01 10:46:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	my_function(unsigned int	i, char	c)
// {
// 	char	c2;

// 	if (((int ) i) >= 0)
// 		c2 = c;
// 	return (c2);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*str;

	if (!s)
		return (0);
	len = ft_strlen(s);
	i = 0;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	while (str != NULL && s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}

// int		main(void)
// {
// 	char	*str = ft_strmapi("", my_function);
// 	printf("%s\n", str);
// 	free(str);
// 	return(0);
// }