/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numara.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:34:01 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/04/04 21:29:34 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_basamak(int k)
{
	size_t	basamak;

	basamak = 0;
	if (k <= 0)
		basamak++;
	while (k != 0)
	{
		k = k / 10;
		basamak++;
	}
	return (basamak);
}

static void	numyerlestir(int m)
{
	static char	numara[] = "0123456789";

	if (m > 9)
		numyerlestir(m / 10);
	write(1, & numara[m % 10], 1);
}

int	print_numara(int s)
{
	int	len;

	if (s == -2147483648)
		return (write(1, "-2147483648", 11));
	len = num_basamak(s);
	if (s < 0)
	{
		write(1, "-", 1);
		s = s * -1;
	}
	numyerlestir(s);
	return (len);
}
