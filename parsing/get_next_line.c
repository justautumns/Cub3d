/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:07:29 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/05/30 17:08:34 by mehmeyil         ###   ########.fr       */
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
