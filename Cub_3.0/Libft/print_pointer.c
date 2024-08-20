/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:02:23 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/30 20:54:32 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static int	counter(unsigned long long number)
{
	int	result;

	result = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 16;
		result++;
	}
	return (result);
}

int	pointer_address(va_list args)
{
	unsigned long long	number;
	char				rev_address[100];
	int					pos;
	unsigned long long	hex;
	int					count;

	number = (unsigned long long)va_arg(args, void *);
	count = counter(number);
	if (!number)
		return (write(1, "(nil)", 5), 5);
	pos = 0;
	while (number > 0)
	{
		hex = number % 16;
		if (hex < 10)
			rev_address[pos++] = hex + '0';
		else
			rev_address[pos++] = hex + 87;
		number /= 16;
	}
	rev_address[pos] = '\0';
	write(1, "0x", 2);
	while (pos--)
		write(1, &rev_address[pos], 1);
	return (count + 2);
}
