/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:03:04 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/06/01 02:48:32 by mtrojano         ###   ########.fr       */
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
	if (texture_check(path) == 1)
		return ("Error: Path is not valid\n");
	while (textures[m++])
		free(textures[m]);
	free(textures);
	return (path);
}
