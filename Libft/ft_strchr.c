/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:50:11 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/05 03:23:08 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	char	*temp_str;

	temp_str = (char *)string;
	while (*temp_str)
	{
		if (*temp_str == (unsigned char)c)
			return (temp_str);
		temp_str ++;
	}
	if (c == 0)
		return (temp_str);
	return (NULL);
}
