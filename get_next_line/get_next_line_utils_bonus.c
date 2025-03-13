/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:14:22 by sooslee           #+#    #+#             */
/*   Updated: 2024/04/11 16:04:33 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (str[cnt])
	{
		cnt ++;
	}
	return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		total_len;
	int		i;
	int		j;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc((total_len + 1) * sizeof(char));
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
	result[total_len] = '\0';
	free((char *)s1);
	return (result);
}

char	*ft_strdup(const char *string)
{
	char		*beduped;
	size_t		i;

	beduped = malloc((ft_strlen(string) + 1) * sizeof(char));
	if (!beduped)
		return (NULL);
	i = 0;
	while (i < ft_strlen(string))
	{
		beduped[i] = string[i];
		i ++;
	}
	beduped[i] = '\0';
	return (beduped);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substring;
	size_t		i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substring[i] = s[start + i];
		i ++;
	}
	substring[i] = '\0';
	return (substring);
}
