/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:23:16 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/13 03:08:41 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	size_t			i;

	if (!(unsigned char *)dst && !(unsigned char *)src)
		return (NULL);
	i = 0;
	if ((unsigned char *)src >= (unsigned char *)dst)
	{
		while (i < num)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i ++;
		}
	}
	else if ((unsigned char *)src < (unsigned char *)dst)
	{
		while (num > 0)
		{
			((unsigned char *)dst)[num - 1] = ((unsigned char *)src)[num - 1];
			num --;
		}
	}
	return ((unsigned char *)dst);
}
