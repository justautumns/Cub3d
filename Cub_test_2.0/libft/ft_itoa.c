/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:33:54 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/15 14:31:22 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	eksiatif(int number)
{
	if (number < 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static int	sayilar(unsigned int number)
{
	size_t	digits;

	if (number == 0)
	{
		return (1);
	}
	digits = 0;
	while (number >= 1)
	{
		number /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char			*string;
	unsigned int	eksi;
	unsigned int	number;
	unsigned int	digits;

	eksi = eksiatif(n);
	if (eksi)
		number = -n;
	else
		number = n;
	digits = sayilar(number);
	string = (char *)malloc(digits + eksi + 1);
	if (!(string))
		return (NULL);
	if (eksi == 1)
		string[0] = '-';
	string[digits + eksi] = '\0';
	while (digits > 0)
	{
		string[(digits - 1) + eksi] = (number % 10) + '0';
		number /= 10;
		digits--;
	}
	return (string);
}
