/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:55:30 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/15 16:04:17 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int	number;
	int	minus;

	number = 0;
	minus = 0;
	while (*nptr == '\f' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\t' || *nptr == '\v' || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
	{
		minus = 1;
		nptr++;
	}
	if (*nptr == '+' && minus == 0)
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		number = number * 10 + *nptr - 48;
		nptr++;
	}
	if (minus == 1)
		number *= -1;
	return (number);
}
/*
int	main()
{
	char	*str = "  	-2147483648";

	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str));
}*/
