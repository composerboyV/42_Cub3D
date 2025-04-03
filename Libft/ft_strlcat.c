/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:44:27 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/14 12:20:59 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		srclen;
	size_t		deslen;
	size_t		i;

	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen + size);
	deslen = ft_strlen(dest);
	if (size <= deslen)
		return (srclen + size);
	i = 0;
	if (size > deslen)
	{
		while (src[i] != '\0' && deslen + i + 1 < size)
		{
			dest[deslen + i] = src[i];
			i ++;
		}
	}
	dest[deslen + i] = '\0';
	return (srclen + deslen);
}
