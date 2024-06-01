/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:36:34 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/06/01 04:09:49 by mtrojano         ###   ########.fr       */
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
		tmp = get_next_line(fd);
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
			line = remove_nl_end(line);
			if (!line)
				return ;
			game->map.map_data[i] = ft_strdup(line);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	game->map.map_data[i] = NULL;
}

void	parse_line(char *line, t_game *game, int *map_start_line, int line_num)
{

	if (ft_strncmp(line, "NO ",3) == 0)
		game->textures.north = get_textures_path(line);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		game->textures.south = get_textures_path(line);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		game->textures.west = get_textures_path(line);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		game->textures.east = get_textures_path(line);
	else if (ft_strncmp(line, "F ", 2) == 0)
		game->colors.floor = parse_color(line);
	else if (ft_strncmp(line, "C ", 2) == 0)
		game->colors.ceiling = parse_color(line);
	else if (line[0] == '1' || line[0] == ' ' || line[0] == '\t')
	{
		if (*map_start_line == -1)
			*map_start_line = line_num;
		game->map.height++;
	}
}

int	parse_cub_file(char *path, t_game *game)
{
	int		fd;
	char	*tmp;
	int		line_num;
	int		map_start_line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line_num = 0;
	map_start_line = -1;
	game->map.height = 0;
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		tmp = remove_nl_end(tmp);
		if (!tmp)
			return (-1);
		parse_line(tmp, game, &map_start_line, line_num);
		free(tmp);
		line_num++;
		tmp = get_next_line(fd);
	}
	close (fd);
	if (map_start_line != -1)
	{
		fd = open(path, O_RDONLY);
		parse_map(fd, game, map_start_line);
		close(fd);
	}
	return (0);
}
