/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:43:13 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/05 05:13:40 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int	len;

	len = ft_strlen(string);
	while (len >= 0)
	{
		if (string[len] == (char) c)
			return ((char *)string + len);
		len --;
	}
	if (c == 0)
		return ((char *)string);
	return (0);
}
