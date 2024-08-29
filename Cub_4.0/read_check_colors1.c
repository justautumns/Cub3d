/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_colors1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:54:03 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/08/29 23:17:24 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub.h"

int	check_format(char *all_values, int i, int comma, int format)
{
	while (all_values[i] != '\n')
	{
		if (all_values[i] != ' ' && all_values[i] != ','
			&& ft_isdigit(all_values[i]) != 2048)
			return (ft_error("Invalid format for color arguments\n"));
		if (all_values[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (ft_error("Invalid format for color arguments\n"));
	i = 0;
	while (all_values[i] != '\n')
	{
		if (all_values[i] == ',')
			format++;
		if (ft_isdigit(all_values[i]) == 2048)
			format -= 1;
		if (format == 2)
			return (ft_error("Invalid format for color arguments\n"));
		i++;
	}
	return (0);
}

int	check_numbers2(t_data *d, char **arguments)
{
	char	**rgb;

	rgb = NULL;
	if (ft_strncmp(arguments[0], "C", 1) == 0)
	{
		if (ft_strlen(arguments[0]) > 1)
			return (-1);
		if (check_format(d->color_c, 0, 0, 0) == -1)
			return (-1);
		rgb = ft_split(d->color_c, ',');
		if (!rgb)
			return (ft_error("Error: malloc failed\n"));
		if (check_for_ceiling(d, rgb) == -1)
			return (free_env(&rgb), -1);
	}
	free_env(&rgb);
	return (0);
}

int	check_space_colors(char **colors)
{
	int	i;
	int	x;

	i = 1;
	while (colors[i])
	{
		x = 0;
		while (colors[i][x])
			x++;
		if (colors[i + 1])
		{
			if (ft_isdigit(colors[i][x - 1]) == 2048 && colors[i + 1][0] != ',')
				return (-1);
		}
		else
		{
			if (ft_isdigit(colors[i][x - 2]) != 2048)
				return (-1);
		}
		i++;
	}
	return (0);
}
