/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:03:04 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/05/30 20:06:02 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_textures_path(char *str)
{
	char	**textures;
	char	*path;
	int		m;

	textures = ft_split(str, ' ');
	path = NULL;
	m = 0;
	if (textures[1])
		path = ft_strdup(textures[1]);
	while (textures[m++])
		free(textures[m]);
	free(textures);
	return (path);
}
