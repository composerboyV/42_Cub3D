/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 01:00:32 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/15 18:33:16 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		total_len;
	int		i;
	int		j;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(total_len * sizeof(char) + 1);
	i = 0;
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i ++;
	}
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j ++;
	}
	result[i + j] = '\0';
	return (result);
}
