/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:54:24 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/07 01:25:19 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	unsigned char	*test;
	unsigned char	*becuppied;
	size_t			i;

	i = 0;
	test = (unsigned char *)dest;
	becuppied = (unsigned char *)source;
	if (!test && !becuppied)
		return (NULL);
	while (i < num)
	{
		test[i] = becuppied[i];
		i ++;
	}
	return (test);
}
