/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:46:08 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/04/04 21:28:01 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hangitip(char a, va_list args)
{
	if (a == '%')
		return (write(1, "%", 1));
	else if (a == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (a == 's')
		return (print_string(va_arg(args, char *)));
	else if (a == 'd' || a == 'i')
		return (print_numara(va_arg(args, int)));
	else if (a == 'p')
		return (print_pointer(va_arg(args, void *)));
	else if (a == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	else if (a == 'x')
		return (print_hex(va_arg(args, unsigned int), 'x'));
	else if (a == 'X')
		return (print_hex(va_arg(args, unsigned int), 'X'));
	return (0);
}

int	ft_printf(const char *tip, ...)
{
	int		k;
	int		len;
	va_list	args;

	if (!tip)
		return (0);
	k = 0;
	len = 0;
	va_start(args, tip);
	while (tip[k])
	{
		if (tip[k] == '%')
		{
			k++;
			len += hangitip(tip[k], args);
		}
		else
			len = len + write(1, &tip[k], 1);
		k++;
	}
	va_end(args);
	return (len);
}
