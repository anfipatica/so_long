/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:51:26 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/10/20 17:38:44 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*aux;
	int		i;

	if (lst == NULL)
		return (0);
	aux = lst;
	i = 0;
	while (aux->next != NULL)
	{
		aux = aux->next;
		i++;
	}
	return (i + 1);
}
