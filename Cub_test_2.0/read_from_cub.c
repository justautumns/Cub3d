/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:16:20 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/08/07 00:34:27 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub.h"

char	*texture_path(char *str)
{
	char	**textures;
	char	*path;
	int		m;

	textures = ft_split(str, ' ');
	path = NULL;
	m = 0;
	if (textures[1])
		path = ft_strdup(textures[1]);
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
