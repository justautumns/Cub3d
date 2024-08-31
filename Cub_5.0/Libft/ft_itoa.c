/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:50:40 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/16 22:22:08 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	convert(int n, int len, char *str)
{
	int	div;

	div = 1;
	len -= 1;
	if (n < 0)
	{
		n *= -1;
		*str = '-';
		str++;
		len--;
	}
	if (len >= 1)
		while (len--)
			div *= 10;
	while (div > 0)
	{
		*str = n / div + 48;
		n = n % div;
		div /= 10;
		str++;
	}
	*str = '\0';
}

static void	convert_min_int(int n, char *str)
{
	int	div;

	div = 100000000;
	n = 214748364;
	*str = '-';
	str++;
	while (div > 0)
	{
		*str = n / div + 48;
		n = n % div;
		div /= 10;
		str++;
	}
	*str = '8';
	str++;
	*str = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = get_len(n);
	if (n == -2147483648)
	{
		str = malloc(12);
		if (!str)
			return (0);
		convert_min_int(n, str);
	}
	else
	{
		str = malloc(len + 1);
		if (!str)
			return (0);
		convert(n, len, str);
	}
	return (str);
}
/*
int	main()
{
	printf("%s\n", ft_itoa(-10));
}*/