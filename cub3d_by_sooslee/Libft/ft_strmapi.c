/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:22:52 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/04 16:15:26 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*alloc;
	int		s_len;
	int		i;

	s_len = ft_strlen(s);
	alloc = malloc(s_len * sizeof(char) + 1);
	if (!alloc)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		alloc[i] = f (i, s[i]);
		i ++;
	}
	alloc[i] = '\0';
	return (alloc);
}
