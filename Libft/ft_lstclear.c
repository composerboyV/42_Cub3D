/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:38:09 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/13 22:00:29 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*del_node;

	del_node = *lst;
	while (*lst != NULL)
	{
		*lst = (*lst)-> next;
		del(del_node -> content);
		free(del_node);
		del_node = *lst;
	}
}
