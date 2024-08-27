/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 07:26:35 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/27 21:27:47 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	have_all_info(t_data *d)
{
	if (d->tex->no_path && d->tex->so_path
		&& d->tex->we_path && d->tex->ea_path
		&& d->color_c && d->color_f)
		return (true);
	return (false);
}

int	finish_reading(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line && ft_strncmp(line, "Error", 5) == 0)
		return (ft_error("Error: malloc failed\n"));
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && ft_strncmp(line, "Error", 5) == 0)
			return (ft_error("Error: malloc failed\n"));
	}
	return (0);
}

int	just_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

int	check_before_map(char *line)
{
	int	i;

	i = 0;
	if (ft_strlen_n(line) > 1)
	{
		if (just_spaces(line) == 0)
			return (-1);
		while (line[i] != '\n' && line[i] != '\0')
		{
			if (line[i] != ' ' && line[i] != '1' && line[i] != '0'
				&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
				&& line[i] != 'E' && line[i] != '\t')
				return (-1);
			i++;
		}
		return (0);
	}
	return (0);
}

int	compare_check(char *name)
{
	if (ft_strncmp(name, "F", 1) == 0)
		return (1);
	if (ft_strncmp(name, "C", 1) == 0)
		return (1);
	if (ft_strncmp(name, "SO", 2) == 0)
		return (2);
	if (ft_strncmp(name, "NO", 2) == 0)
		return (2);
	if (ft_strncmp(name, "WE", 2) == 0)
		return (2);
	if (ft_strncmp(name, "EA", 2) == 0)
		return (2);
	return (-1);
}
