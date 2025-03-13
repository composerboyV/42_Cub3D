/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:54:25 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/13 00:18:13 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed_str;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = ft_strlen(s1) -1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start ++;
	while (end > start && ft_strchr(set, s1[end]))
		end --;
	if (start > end)
		return (ft_strdup(""));
	trimed_str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!trimed_str)
		return (NULL);
	i = 0;
	while (start < end + 1)
	{
		trimed_str[i] = s1[start];
		i ++;
		start ++;
	}
	trimed_str[i] = '\0';
	return (trimed_str);
}
