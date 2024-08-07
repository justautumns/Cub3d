/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorchecks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:50:22 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/08/07 11:55:37 by mtrojano         ###   ########.fr       */
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
