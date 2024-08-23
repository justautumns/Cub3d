/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 03:36:24 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/08/23 18:06:24 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// int	check_rgb_is_valid(char **str)
// {
// 	int	m;
// 	int	k;

// 	m = 0;
// 	while(str[m])
// 	{
// 		k = 0;
// 		while (str[m][k])
// 		{
// 			if (str[m][k] == ' ' || str[m][k] == ',')
// 				return (-1);
// 			k++;
// 		}
// 		printf("%s\n", str[m]);
// 		m++;
// 	}
// 	return (0);
// }
int	player_pos_valid(t_data *d)
{
	int	m;
	int	k;
	int	there;

	m = 0;
	there = 0;
	while (d->map[m])
	{
		k = 0;
		while (d->map[m][k] != '\n')
		{
			if (d->map[m][k] == 'N' || d->map[m][k] == 'S'
				|| d->map[m][k] == 'E' || d->map[m][k] == 'W')
				there++;
			k++;
		}
		m++;
	}
	if (there != 1)
		return (-1);
	return (0);
}

int	check_space(char **map)
{
	int	m;
	int	k;

	m = 1;
	while (map[m])
	{
		k = 1;
		while (map[m][k] != '\n')
		{
			if (map[m][k] == '0' || map[m][k] == 'N' || map[m][k] == 'W'
				|| map[m][k] == 'S' || map[m][k] == 'E')
			{
				if ((map[m -1][k] == ' ') || (map[m + 1][k] == ' ')
					|| (map[m][k - 1] == ' ') || (map[m][k + 1] == ' '))
					return (-1);
			}
			k++;
		}
		m++;
	}
	return (0);
}
