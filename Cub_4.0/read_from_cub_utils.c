/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_cub_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:53:41 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/30 00:54:21 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*skip_nl_before_map(int fd, char *line)
{
	char	*skip_line;

	if (!line)
		return (ft_error("Error: Map incomplete\n"), NULL);
	if (line && ft_strncmp(line, "Error", 5) == 0)
		return (ft_error("Error: malloc failed\n"), NULL);
	skip_line = ft_strdup(line);
	if (!skip_line)
		return (ft_error("Error: malloc failed\n"), NULL);
	while (skip_line[0] == '\n')
	{
		free(skip_line);
		skip_line = get_next_line(fd);
		if (!skip_line)
			return (NULL);
		if (skip_line && ft_strncmp(skip_line, "Error", 5) == 0)
			return (free(skip_line), ft_error("Error: malloc failed\n"), NULL);
	}
	return (skip_line);
}

int	check_empty_line_betweeen(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	y--;
	if (y > 1 && map[y - 1] && map[y - 1][0] == '\n')
		return (-1);
	return (0);
}
