/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:02:35 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/06/01 03:57:53 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	arg_check(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 4] != '.' || str[i - 3] != 'c'
		|| str[i - 2] != 'u' || str[i - 1] != 'b')
		return (1);
	return (0);
}
int	texture_check(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 4] != '.' || str[i - 3] != 'x'
		|| str[i - 2] != 'p' || str[i - 1] != 'm')
		return (1);
	return (0);
}
