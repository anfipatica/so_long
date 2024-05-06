/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:26:30 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/10/22 15:56:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		position[2];
	char	*s2;

	i = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	position[0] = i;
	i = ft_strlen(s1);
	while (i != -1 && ft_strrchr(set, s1[i]) != NULL)
		i--;
	position[1] = i;
	if (position[0] > position[1])
		return (ft_strdup(""));
	s2 = ft_calloc(((position[1] - position[0]) + 2), sizeof(char));
	if (s2 == NULL)
		return (0);
	i = -1;
	while ((position[0] + ++i) <= position[1])
		s2[i] = s1[position[0] + i];
	return (s2);
}

// int		main(void)
// {
// 	printf("%s\n",ft_strtrim("       ","  "));
// 	return (0);
// }