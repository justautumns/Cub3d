/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:22:56 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/04/04 21:22:05 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	hex_basamak(unsigned int k)
{
	int	m;

	m = 0;
	if (k == 0)
		return (1);
	while (k != 0)
	{
		m++;
		k = k / 16;
	}
	return (m);
}

static void	hexyerlestir(unsigned int numara, char x)
{
	static char	buyukharf[] = "0123456789ABCDEF";
	static char	kucukharf[] = "0123456789abcdef";

	if (numara >= 16 && x)
		hexyerlestir(numara / 16, x);
	if (x == 'X')
		write(1, &buyukharf[numara % 16], 1);
	else
		write(1, &kucukharf[numara % 16], 1);
}

int	print_hex(unsigned int numara, char x)
{
	hexyerlestir(numara, x);
	return (hex_basamak(numara));
}
