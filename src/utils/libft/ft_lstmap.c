/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:19:38 by ymunoz-m          #+#    #+#             */
/*   Updated: 2023/10/20 20:24:25 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_lst;
	t_list	*next_node;
	void	*content;

	head_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
			return (ft_lstclear(&head_lst, del), NULL);
		next_node = ft_lstnew(content);
		if (!next_node)
		{
			del(content);
			ft_lstclear(&head_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&head_lst, next_node);
		lst = lst->next;
	}
	return (head_lst);
}
