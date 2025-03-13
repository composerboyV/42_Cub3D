/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:18:28 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/11 13:48:07 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_node;

	if (lst == NULL)
		return (0);
	last_node = lst;
	while (last_node -> next != NULL)
	{
		last_node = last_node -> next;
	}
	return (last_node);
}
