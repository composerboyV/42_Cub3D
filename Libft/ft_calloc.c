/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:47:20 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/08 23:21:51 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include"libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*alloc;

	alloc = malloc(num * size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, num * size);
	return (alloc);
}
