/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:49:26 by mtrojano          #+#    #+#             */
/*   Updated: 2023/10/12 14:13:20 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

static int	percent(void)
{
	write(1, "%%", 1);
	return (1);
}

static int	deal_with_that(const char *format, va_list args)
{
	char	specifier;
	int		count;

	count = 0;
	specifier = *format;
	if (specifier == 'c')
		count += character(args);
	if (specifier == 's')
		count += string(args);
	if (specifier == 'd' || specifier == 'i')
		count += integer(args);
	if (specifier == 'u')
		count += uninteger(args);
	if (specifier == 'p')
		count += pointer_address(args);
	if (specifier == 'x')
		count += hex_lower(args);
	if (specifier == 'X')
		count += hex_upper(args);
	if (specifier == '%')
		count += percent();
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += deal_with_that(format, args);
			format++;
		}
		if (*format && *format != '%')
		{
			write(1, format, 1);
			format++;
			count++;
		}
	}
	return (count);
}
/*
int	main()
{
	//int num = 5;
	int *ptr = NULL;
	int *ptr2 = NULL;

	printf("Hex: %p  %p\n", LONG_MIN, LONG_MAX);
	ft_printf("Hex: %p  %p\n", LONG_MIN, LONG_MAX);
}
*/