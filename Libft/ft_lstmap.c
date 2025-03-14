/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:42:34 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/12 22:45:11 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*new_node;
	t_list	*new_nodemaker;

	new_node = ft_lstnew(f(lst -> content));
	new_nodemaker = new_node;
	lst = lst -> next;
	while (lst)
	{
		new_nodemaker -> next = ft_lstnew(f(lst -> content));
		new_nodemaker = new_nodemaker -> next;
		while (new_node == NULL)
		{
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		lst = lst -> next;
	}
	return (new_node);
}
