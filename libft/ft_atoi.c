/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:22:40 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/09 13:45:03 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	m;
	int	sign;
	int	result;

	sign = 1;
	m = 0;
	while (str[m] == '\t' || str[m] == '\n' || str[m] == '\v'
		|| str[m] == '\f' || str[m] == '\r' || str[m] == ' ')
		m++;
	if (str[m] == '-')
	{
		sign = -1;
		m++;
	}
	if (str[m] == '+' && sign == 1)
		m++;
	result = 0;
	while (str[m] >= '0' && str[m] <= '9')
		result = (result * 10) + (str[m++] - '0');
	return (result * sign);
}
