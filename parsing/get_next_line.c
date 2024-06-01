/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:07:29 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/06/01 04:09:55 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_next_line(int fd)
{
	int		n;
	int		index;
	char	character;
	char	buffer[1025];

	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	n = read(fd, &character, 1);
	while (n > 0)
	{
		buffer[index++] = character;
		if (index >= 1024 || character == '\n')
			break ;
		n = read(fd, &character, 1);
	}
	if (n < 0 || (n == 0 && index == 0))
		return (NULL);
	buffer[index] = '\0';
	return (ft_strdup(buffer));
}

char	*remove_nl_end(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(ft_strlen(line));
	if (!tmp)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = '\0';
	free(line);
	return (tmp);
}
