/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:24:19 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/09/02 15:58:04 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_tab(t_data *d)
{
	int	m;
	int	k;

	m = 0;
	while (d->map[m])
	{
		k = 0;
		while (d->map[m][k])
		{
			if (d->map[m][k] == '\t')
				return (-1);
			k++;
		}
		m++;
	}
	return (0);
}

int	wall_check2(char **map, int k, int m)
{
	while (map[m])
	{
		k = 0;
		while (map[m][k] == 32)
			k++;
		if (map[m][k] != '1')
			return (-1);
		m++;
	}
	m = 0;
	while (map[m])
		m++;
	m--;
	k = 0;
	while (map[m][k] != '\n' && map[m][k] != '\0')
	{
		while (map[m][k] == 32)
			k++;
		if (map[m][k] != '1')
			return (-1);
		k++;
	}
	return (0);
}

int	wall_check(char **map)
{
	int	m;
	int	k;

	k = 0;
	while (map[0][k] == ' ')
		k++;
	while (map[0][k] != '\n')
	{
		if (map[0][k] != '1' && map[0][k] != ' ')
			return (-1);
		k++;
	}
	if (wall_check2(map, 0, 0) == -1)
		return (-1);
	m = 0;
	while (map[m])
	{
		k = 0;
		while (map[m][k] != '\n' && map[m][k] != '\0')
			k++;
		if (map[m][k - 1] != '1' && map[m][k - 1] != ' ')
			return (-1);
		m++;
	}
	return (0);
}

int	check_actual_map(t_data *data)
{
	if (!data->map[0])
		return (-1);
	if (check_tab(data) == -1)
		return (ft_error("Map cannot have tabs!\n"));
	else if (wall_check(data->map) == -1)
		return (ft_error("Map is not protected by walls\n"));
	else if (player_pos_valid(data) == -1)
		return (ft_error("Map has multiple or none spawning pos\n"));
	else if (check_wall_lenght(data->map, 0, 0, 0) == -1)
		return (ft_error("Map is not protected by walls\n"));
	else if (check_space(data->map) == -1)
		return (ft_error("Map has void or Player is in the void\n"));
	return (0);
}
