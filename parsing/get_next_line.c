/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:07:29 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/05/28 13:53:54 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strdup(char *str)
{
	int		i;
	int		m;
	char	*tmp;

	m = ft_strlen(str) + 1;
	tmp = (char *) malloc(sizeof(char) * m);
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

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
