/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:42:04 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/11 14:00:22 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*iter_node;

	if (lst == NULL)
		return ;
	iter_node = lst;
	while (lst != NULL)
	{
		lst = lst -> next;
		f(iter_node -> content);
		iter_node = lst;
	}
}
