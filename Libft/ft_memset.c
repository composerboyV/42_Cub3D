/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:58:48 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/04 22:23:16 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned char	*test;
	size_t			i;

	i = 0;
	test = (unsigned char *) dest;
	while (i < count)
	{
		test[i] = (unsigned char)c;
		i ++;
	}
	return (test);
}
