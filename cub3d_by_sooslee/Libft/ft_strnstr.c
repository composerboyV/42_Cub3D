/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:27:16 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/13 16:13:53 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp_big;

	temp_big = (char *)big;
	i = 0;
	if (little[0] == '\0')
		return (temp_big);
	while (i < len && temp_big[i] != '\0')
	{
		j = 0;
		while (temp_big[i + j] == little[j] && i + j < len)
		{
			j ++;
			if (little[j] == '\0')
				return (&temp_big[i]);
		}
		i ++;
	}
	return (NULL);
}
