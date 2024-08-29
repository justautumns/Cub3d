/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 03:36:24 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/08/30 00:58:11 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
		while (d->map[m][k] != '\n' && d->map[m][k] != '\0')
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

int	check_dif(char *str, int dif)
{
	if (dif == 0)
		return (0);
	while (str[dif] != '\n')
	{
		if (str[dif] != '1')
			return (-1);
		dif++;
	}
	return (0);
}

int	check_wall_lenght(char **map, int m, int k, int dif)
{
	while (map[m])
	{
		k = 1;
		while (map[m][k] != '\n' && map[m][k] != '\0')
		{
			dif = 0;
			if (map[m + 1] && ft_strlen_n(map[m + 1]) < ft_strlen_n(map[m]))
			{
				dif = ft_strlen_n(map[m + 1]);
				if (check_dif(map[m], dif) == -1)
					return (-1);
			}
			else if (map[m + 1]
				&& ft_strlen_n(map[m + 1]) > ft_strlen_n(map[m]))
			{
				dif = ft_strlen_n(map[m]);
				if (check_dif(map[m + 1], dif) == -1)
					return (-1);
			}
			k++;
		}
		m++;
	}
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
		while (map[m][k] != '\n' && map[m][k] != '\0')
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
