/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorchecks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:50:22 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/08/18 13:36:02 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub.h"

int	arg_check(char *str)
{
	int	m;

	m = ft_strlen_n(str);
	if (str[m - 4] != '.' || str[m - 3] != 'c'
		|| str[m - 2] != 'u' || str[m - 1] != 'b')
		return (-1);
	return (0);
}
int	texture_check(char *str)
{
	int	m;

	m = ft_strlen_n(str);
	if (str[m - 5] != '.' || str[m - 4] != 'x'
		|| str[m - 3] != 'p' || str[m - 2] != 'm')
		return (-1);
	return (0);
}
int	ft_error(char *str)
{
	write(2, str, ft_strlen_n(str));
	return (-1);
}

int	check_map(char *str, t_data *d)
{
	int		fd;
	//char	*line;

	fd = open(str, O_RDONLY);
	if (fd < 1)
		return (-1);
	if (read_from_map(fd, d) == -1)
		return (-1);
	close(fd);
	return (0);
}

int	check_tab(t_data *d)
{
	int	m;
	int	k;

	m = 0;
	while (m < d->map_max_width)
	{
		k = 0;
		while (k < d->map_max_height)
		{
			if (d->map[m][k] == '\t')
				return (-1);
			k++;
		}
		m++;
	}
	return (0);
}
int	wall_check(t_data *d)
{
	int	m;

	m = 0;
	while (m < d->map_max_height)
	{
		if ((d->map[0][m] != '1') || (d->map[d->map_max_width - 1][m] != '1'))
			return (-1);
		m++;
	}
	m = 0;
	while(m < d->map_max_width)
	{
		if ((d->map[m][0] != '1') || (d->map[m][d->map_max_height - 1] != '1'))
			return (-1);
		m++;
	}
	return (0);
}

int	check_space(t_data *d)
{
	int	m;
	int	k;

	m = 1;
	while (m < d->map_max_width - 1)
	{
		k = 1;
		while (k < d->map_max_height -1)
		{
			if (d->map[m][k] == '0')
			{
				if ((d->map[m -1][k] == ' ') || (d->map[m + 1][k] == ' ')
					 || (d->map[m][k - 1] == ' ') || (d->map[m][k + 1] == ' '))
					return (-1);
			}
			k++;
		}
		m++;
	}
	return (0);
}
