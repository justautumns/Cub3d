/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:54:11 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/05/30 20:01:44 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parse_color(char *str)
{
	char	**colors;
	char	**rgb;
	int		color;
	int		m;

	colors = ft_split(str, ' ');
	color = 0;
	m = 0;
	if (colors[1])
	{
		rgb = ft_split(colors[1], ',');
		if (rgb[0] && rgb[1] && rgb[2])
			color = (ft_atoi(rgb[0]) << 16) | (ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]));
		while (rgb[m++])
			free(rgb[m]);
		free(rgb);
	}
	m = 0;
	while (colors[m++])
		free(colors[m]);
	free(colors);
	return (color);
}
