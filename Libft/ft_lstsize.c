/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:48:36 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/11 13:44:51 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*count_node;
	int		count;

	if (lst == NULL)
		return (0);
	count_node = lst;
	count = 0;
	while (count_node -> next != NULL)
	{
		count ++;
		count_node = count_node -> next;
	}
	return (count + 1);
}
