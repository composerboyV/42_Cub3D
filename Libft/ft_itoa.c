/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:19:06 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/09 01:13:32 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	intlen(long long n)
{
	int	len;

	if (n == 0)
		len = 1;
	else if (n > 0)
		len = 0;
	else
		len = 1;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa0(long long n)
{
	char	*str;

	if (n == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	return (0);
}

char	*ft_itoa3(long long n)
{
	char		*str;
	char		result;
	int			len;

	len = intlen(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		result = n % 10 + '0';
		str[len - 1] = result;
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long long	num;

	num = (long long)n;
	if (num == 0)
		return (ft_itoa0(num));
	else
		return (ft_itoa3(num));
}

/*
#include <stdio.h>
int	main()
{
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(483648));
	printf("%s\n", ft_itoa(-21474));
	printf("%s\n", ft_itoa(21474));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(100));
}*/
