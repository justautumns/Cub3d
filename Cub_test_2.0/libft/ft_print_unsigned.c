/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:39:04 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/04/04 21:29:28 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	unsigned_basamak(unsigned int k)
{
	unsigned int	basamak;

	basamak = 0;
	if (k == 0)
		return (1);
	while (k != 0)
	{
		basamak = basamak + 1;
		k = k / 10;
	}
	return (basamak);
}

void	unsignedyerlestir(unsigned int m)
{
	static char	numara[] = "0123456789";

	if (m > 9)
		unsignedyerlestir(m / 10);
	write(1, & numara[m % 10], 1);
}

int	print_unsigned(unsigned int s)
{
	unsignedyerlestir(s);
	return (unsigned_basamak(s));
}
