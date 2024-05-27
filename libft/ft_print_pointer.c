/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:00:24 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/04/04 21:26:07 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	pointer_basamak(unsigned long long k)
{
	unsigned int	basamak;

	basamak = 0;
	if (k == 0)
		return (1);
	while (k != 0)
	{
		basamak = basamak + 1;
		k = k / 16;
	}
	return (basamak);
}

static void	pointeryerlestir(unsigned long long m)
{
	static char	numara[] = "0123456789abcdef";

	if (m >= 16)
		pointeryerlestir(m / 16);
	write(1, & numara[m % 16], 1);
}

int	print_pointer(void *p)
{
	if (p == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	pointeryerlestir((unsigned long long)p);
	return (pointer_basamak((unsigned long long)p) + 2);
}
