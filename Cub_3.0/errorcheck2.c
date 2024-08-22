/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:24:19 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/08/22 18:33:02 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_tab(t_data *d)
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
int	wall_check(char **map)
{
	int	m;
	int	k;

	m = 0;
	k = 0;
	while (map[m] != NULL)
	{
		k = 0;
		while(map[m][k])
		{
			//printf("%d\n", m);
			if (map[0][k] != '1')
				return (-1);
			k++;
		}
		//printf("%d\n", m);
		if (map[m][0] != '1')
			return (-1);
		else if (map[m][k -1] != '1')
			return (-1);
		//printf("%d\n", m);
		m++;
	}
	return (0);
}
// int	check_space(t_data *d)
// {
// 	int	m;
// 	int	k;

// 	m = 1;
// 	while (m < d->map_max_width - 1)
// 	{
// 		k = 1;
// 		while (k < d->map_max_height -1)
// 		{
// 			if (d->map[m][k] == '0')
// 			{
// 				if ((d->map[m -1][k] == ' ') || (d->map[m + 1][k] == ' ')
// 					 || (d->map[m][k - 1] == ' ') || (d->map[m][k + 1] == ' '))
// 					return (-1);
// 			}
// 			k++;
// 		}
// 		m++;
// 	}
// 	return (0);
// }

int	check_actual_map(t_data *data)
{
	if (check_tab(data) == -1)
		return (ft_error("Map cannot have tabs!\n"));
	else if (wall_check(data) == -1)
		return (ft_error("Map is not protected by walls\n"));
	else if (check_space(data) == -1)
		return (-1);
	return (0);
}
