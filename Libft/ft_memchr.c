/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:50:21 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/04 22:31:08 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	char	*buffer;
	size_t	i;

	buffer = (char *)buf;
	i = 0;
	while (i < count)
	{
		if (buffer[i] == (char) c)
			return (((char *)buffer + i));
		i ++;
	}
	return (NULL);
}
