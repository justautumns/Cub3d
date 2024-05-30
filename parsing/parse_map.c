/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:36:34 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/05/30 20:13:02 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find_map_height(int fd)
{
	char	*tmp;
	int		height;

	height = 0;
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		if (tmp[0] != '\0' && tmp[0] != '\n')
			height++;
		free(tmp);
	}
	return (height);
}
void	parse_map(int fd, t_game *game, int start_line)
{
	int		i;
	char	*line;

	i = 0;
	game->map.map_data = (char **) malloc (sizeof(char *) * (game->map.height + 1));
	if (!game->map.map_data)
		return ;
	while (i < start_line)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] != '\0' && line[0] != '\n')
		{
			game->map.map_data[i] = ft_strdup(line);
			i++;
		}
		free(line);
	}
	game->map.map_data[i] = NULL;
}
