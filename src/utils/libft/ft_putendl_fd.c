/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:47:29 by marvin            #+#    #+#             */
/*   Updated: 2023/10/02 18:47:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	int	fd = open("test",O_RDWR | O_APPEND);
// 	char	*s = "PPPP";
// 	ft_putendl_fd(s, fd);
// 	printf("fd vale: %d\n",fd);
// 	close(fd);
// }