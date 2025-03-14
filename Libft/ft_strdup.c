/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:11:54 by sooslee           #+#    #+#             */
/*   Updated: 2025/03/07 14:11:13 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *string)
{
	char		*beduped;
	size_t		i;

	beduped = malloc(ft_strlen(string) * sizeof(char) + 1);
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
