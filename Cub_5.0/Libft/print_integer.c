/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:38:21 by mtrojano          #+#    #+#             */
/*   Updated: 2023/12/05 19:48:19 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	get_len_pf(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (11);
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

int	integer(va_list args)
{
	int		number;
	int		count;
	int		pos;
	char	*digits;

	pos = 0;
	number = va_arg(args, int);
	count = get_len_pf(number);
	digits = ft_itoa(number);
	if (!digits)
		return (0);
	while (digits[pos])
	{
		write(1, &digits[pos], 1);
		pos++;
	}
	free(digits);
	return (count);
}
