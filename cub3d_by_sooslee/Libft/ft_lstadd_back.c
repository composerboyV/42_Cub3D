/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:47:50 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/11 13:52:09 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur_node;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	cur_node = *lst;
	while (cur_node -> next != NULL)
	{
		cur_node = cur_node -> next;
	}
	cur_node -> next = new;
}
