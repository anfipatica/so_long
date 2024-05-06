/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:20:19 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/10/22 19:37:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;

// 	node1 = ft_lstnew("1");
// 	node2 = ft_lstnew("2");
// 	printf("content nodo1: %s\n",(char *)(node1->content));
// 	printf("p nodo1: %p\n",node1->next);
// 	printf("content nodo2: %s\n",(char *)(node2->content));
// 	printf("p nodo1: %p\n",node2->next);
// 	ft_lstadd_front(&node1, node2);
// 	printf("La lista tiene una longitud de: %d\n", ft_lstsize(node2));
// 	return(0);
// }