/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:14:02 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/05/12 13:27:35 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_memory(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

char	*write_word(char const *s, int len)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (0);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

int	count_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c)
			count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	int				j;
	int				len;
	int				n;
	char			**str;

	i = 0;
	j = -1;
	n = count_words(s, c);
	str = ft_calloc(n + 1, sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (++j < n)
	{
		len = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		i--;
		while (s[++i] != c && s[i] != '\0')
			len++;
		str[j] = write_word(&s[i - len], len);
		if (str[j] == NULL)
			return (free_memory(str, j), NULL);
	}
	return (str);
}
// int		main(void)
// {
// 	char const	*s = "hello!";
// 	char 	c = 32;
// 	char	**str;

// 	str = ft_split(s, c);
// 	for (int i = 0; str[i]; i++)
// 	{
// 		printf("%s\n", str[i]);
// 	}

// 	return (0);
// }