/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:46:13 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/29 23:24:28 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

static int	get_len_unint(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	convert_unint(unsigned int n, int len, char *str)
{
	unsigned int	div;

	div = 1;
	len -= 1;
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

static char	*ft_itoa_unint(unsigned int n)
{
	char	*str;
	int		len;

	len = get_len_unint(n);
	str = malloc(len + 1);
	if (!str)
		return (0);
	convert_unint(n, len, str);
	return (str);
}

int	uninteger(va_list args)
{
	int				count;
	int				pos;
	unsigned int	number;
	char			*digits;

	pos = 0;
	number = va_arg(args, unsigned int);
	count = get_len_unint(number);
	digits = ft_itoa_unint(number);
	while (digits[pos])
	{
		write(1, &digits[pos], 1);
		pos++;
	}
	free(digits);
	return (count);
}
