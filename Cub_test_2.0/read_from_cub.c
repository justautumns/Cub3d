/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:16:20 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/08/07 15:01:17 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub.h"

int	check_other_two_directions(t_data *d, char *dir, char *path)
{
	if (ft_strncmp(dir, "WE", 2) == 0)
	{
		if (d->tex->we_path)
			return (ft_error("Cannot have more than one WE\n"));
		d->tex->we_path = ft_strdup(path);
		if (!d->tex->we_path)
			return (ft_error("Error: malloc failed\n"));
		return (0);
	}
	if (ft_strncmp(dir, "EA", 2) == 0)
	{
		if (d->tex->ea_path)
			return (ft_error("Cannot have more than one EA\n"));
		d->tex->ea_path = ft_strdup(path);
		if (!d->tex->ea_path)
			return (ft_error("Error: malloc failed\n"));
		return (0);
	}
	return (-1);
}

int	check_directions(t_data *d, char *dir, char *path)
{
	if (ft_strncmp(dir, "NO", 2) == 0)
	{
		if (d->tex->no_path)
			return (ft_error("Cannot have more than one NO\n"));
		d->tex->no_path = ft_strdup(path);
		if (!d->tex->no_path)
			return (ft_error("Error: malloc failed\n"));
		return (0);
	}
	if (ft_strncmp(dir, "SO", 2) == 0)
	{
		if (d->tex->so_path)
			return (ft_error("Cannot have more than one SO\n"));
		d->tex->so_path = ft_strdup(path);
		if (!d->tex->so_path)
			return (ft_error("Error: malloc failed\n"));
		return (0);
	}
	if (check_other_two_directions(d, dir, path) == 0)
		return (0);
	return (-1);
}

int	texture_path(t_data *d, char *str)
{
	char	**textures;

	textures = ft_split(str, ' ');
	if (!textures)
		return (-1);
	if (!textures[1])
		return (free_env(&textures),
			ft_error("Error: Too little arguments for texture\n"));
	if (textures[2])
		return (free_env(&textures),
			ft_error("Error: Too many arguments for texture\n"));
	if (texture_check(textures[1]) == -1)
		return (free_env(&textures),
			ft_error("Error: Texture extension not valid\n"));
	if (check_directions(d, textures[0], textures[1]) == -1)
		return (free_env(&textures), -1);
	free_env(&textures);
	return (0);
}

bool	have_all_paths(t_data *d)
{
	if (d->tex->no_path && d->tex->so_path
		&& d->tex->we_path && d->tex->ea_path)
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

int	check_line(char *line, t_data *d)
{
	if (line && ft_strncmp(line, "Error", 5) == 0)
		return (-1); //return (free(line), -1);
	if (line && ft_strncmp(line, "\n", 1) != 0)
	{
		if (texture_path(d, line) == -1)
			return (-1); //return (free(line), finish_reading(fd), -1);
	}
	return (0);
}

int	read_from_map(int fd, t_data *d)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (ft_error("Error: Map is empty\n"));
	if (line && ft_strncmp(line, "Error", 5) == 0)
		return (ft_error("Error: malloc failed\n"));
	while (line && have_all_paths(d) == false)
	{
		if (check_line(line, d) == -1)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	finish_reading(fd);
	return (0);
}
