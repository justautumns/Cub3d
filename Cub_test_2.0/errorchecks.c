/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorchecks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:50:22 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/08/07 01:01:02 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub.h"

int	arg_check(char *str)
{
	int	m;

	m = ft_strlen(str);
	if (str[m - 4] != '.' || str[m - 3] != 'c'
		|| str[m - 2] != 'u' || str[m - 1] != 'b')
		return (-1);
	return (0);
}
int	texture_check(char *str)
{
	int	m;

	m = ft_strlen(str);
	if (str[m - 4] != '.' || str[m - 3] != 'x'
		|| str[m - 2] != 'p' || str[m - 1] != 'm')
		return (-1);
	return (0);
}
int	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (-1);
}
