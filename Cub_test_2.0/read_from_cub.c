/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:16:20 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/08/07 03:41:58 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub.h"

char	*texture_path(char *str)
{
	char	**textures;
	char	*path;
	int		m;

	textures = ft_split(str, ' ');
	if (!textures)
		return (NULL);
	path = NULL;
	m = 0;
	if (textures[2])
		return (free_env(&textures), NULL);
	if (textures[1])
		path = ft_strdup(textures[1]);
	if (!path)
		return (NULL);
	if (texture_check(path) == -1)
		return (ft_error("Error: Not a valid path"));
	while (textures[m])
	{
		free(textures[m]);
		m++;
	}
	free(textures);
	return (path);
}
int	exract_paths(char *str)
{
	if (!str)
		return (-1);

}
int	read_from_map(int fd, t_data *data, char *str)
{
	char	*line;

	data->tex = malloc(sizeof(t_tex));
	if (!data->tex)
		return (-1);
	data->tex->tex_path = malloc(5 * sizeof(char *));
	if (!data->tex->tex_path)
		return (-1);
	data->tex->tex_path[0] = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (ft_strncmp(line, "Error", 5) == 0)
			return (-1);
		if (ft_strncmp(line, str, 2) == 0)
			data->tex->tex_path = add_to_array(data->tex->tex_path, texture_path(line));
		else
			return (-1);
	}
	return (0);
}

