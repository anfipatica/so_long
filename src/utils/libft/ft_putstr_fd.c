/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:21:18 by marvin            #+#    #+#             */
/*   Updated: 2023/10/02 18:21:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
}

// int	main(void)
// {
// 	int	fd = open("test",O_WRONLY | O_APPEND);
// 	char	*s = "PPPP";
// 	ft_putstr_fd(s, fd);
// 	printf("fd vale: %d\n",fd);
// 	close(fd);
// }