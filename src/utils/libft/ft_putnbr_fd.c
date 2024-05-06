/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:18:16 by marvin            #+#    #+#             */
/*   Updated: 2023/10/02 19:18:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str[10];
	int		i;

	i = 0;
	if (n < 0 && n != -2147483648)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	while (--i >= 0)
		write(fd, &str[i], 1);
}

// int	main(void)
// {
// 	int	n = -9994545;
// 	int	fd = open("test", O_WRONLY);
// //
// 	ft_putnbr_fd(n, fd);
// 	printf("fd de test vale: %d\n",fd);
// 	close(fd);
// 	return (0);
// }