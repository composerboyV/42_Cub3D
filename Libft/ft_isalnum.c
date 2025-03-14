/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:00:49 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/05 01:48:19 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{	
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
int main()
{
	printf("True : %d\n", ft_isalnum(5));
	printf("True : %d\n", ft_isalnum('c'));
	printf("True : %d\n", ft_isalnum('a'));
	printf("True : %d\n", ft_isalnum('A'));
	printf("True : %d\n", ft_isalnum('Z'));
	printf("True : %d\n", ft_isalnum('*'));
}*/
