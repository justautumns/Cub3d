/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:01:26 by mtrojano          #+#    #+#             */
/*   Updated: 2023/10/01 21:40:40 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	hex_lower(va_list args)
{
	unsigned int	number;
	int				pos;
	int				hex;
	int				count;
	char			rev_num[50];

	number = va_arg(args, unsigned int);
	pos = 0;
	if (number == 0)
		return (write(1, "0", 1), 1);
	while (number > 0)
	{
		hex = number % 16;
		if (hex < 10)
			rev_num[pos] = hex + '0';
		else
			rev_num[pos] = hex + 87;
		number /= 16;
		pos++;
	}
	rev_num[pos] = '\0';
	count = pos;
	while (pos--)
		write(1, &rev_num[pos], 1);
	return (count);
}
