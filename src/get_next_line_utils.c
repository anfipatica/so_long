/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:15:33 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/05/06 21:22:53 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

char	*gnl_strdup(char *s1, int n)
{
	char	*s2;
	int		i;

	if (!s1 || n <= 0)
		return (NULL);
	s2 = ft_calloc((n + 1), sizeof(char));
	if (!s2)
		return (NULL);
	i = -1;
	while (++i < n && s1[i])
		s2[i] = s1[i];
	return (s2);
}