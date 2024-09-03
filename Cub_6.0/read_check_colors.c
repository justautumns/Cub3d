/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 07:22:03 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/31 21:49:18 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	assign_fc(t_data *d, char *name, char *all_values)
{
	if (check_format(all_values, 0, 0, 0) == -1)
		return (-1);
	if (ft_strncmp(name, "F", 1) == 0)
	{
		if (d->color_f)
			return (ft_error("Cannot have more than one F\n"));
		d->color_f = ft_strdup(all_values);
		if (!d->color_f)
			return (ft_error("Error: malloc failed\n"));
	}
	if (ft_strncmp(name, "C", 1) == 0)
	{
		if (d->color_c)
			return (ft_error("Cannot have more than one C\n"));
		d->color_c = ft_strdup(all_values);
		if (!d->color_c)
			return (ft_error("Error: malloc failed\n"));
	}
	return (0);
}

int	join_assign_fc_colors(t_data *d, char **arguments)
{
	char	*all_values;
	int		i;

	i = 1;
	all_values = NULL;
	while (arguments[i])
	{
		all_values = ft_strjoin_gnl(all_values, arguments[i]);
		if (!all_values)
			return (ft_error("Error: malloc failed\n"));
		i++;
	}
	if (assign_fc(d, arguments[0], all_values) == -1)
		return (free(all_values), -1);
	free(all_values);
	return (0);
}

int	check_for_floor(t_data *d, char **rgb)
{
	if (!rgb[2] || rgb[3])
		return (ft_error("Invalid arguments in map\n"));
	if (!(ft_atoi(rgb[0]) >= 0 && ft_atoi(rgb[0]) <= 255)
		|| !(ft_atoi(rgb[1]) >= 0 && ft_atoi(rgb[1]) <= 255)
		|| !(ft_atoi(rgb[2]) >= 0 && ft_atoi(rgb[2]) <= 255))
		return (ft_error("Invalid arguments in map\n"));
	else
	{
		d->colors->f_r = ft_atoi(rgb[0]);
		d->colors->f_g = ft_atoi(rgb[1]);
		d->colors->f_b = ft_atoi(rgb[2]);
	}
	return (0);
}

int	check_for_ceiling(t_data *d, char **rgb)
{
	if (!rgb[2] || rgb[3])
		return (ft_error("Invalid arguments in map\n"));
	if (!(ft_atoi(rgb[0]) >= 0 && ft_atoi(rgb[0]) <= 255)
		|| !(ft_atoi(rgb[1]) >= 0 && ft_atoi(rgb[1]) <= 255)
		|| !(ft_atoi(rgb[2]) >= 0 && ft_atoi(rgb[2]) <= 255))
		return (ft_error("Invalid arguments in map\n"));
	else
	{
		d->colors->c_r = ft_atoi(rgb[0]);
		d->colors->c_g = ft_atoi(rgb[1]);
		d->colors->c_b = ft_atoi(rgb[2]);
	}
	return (0);
}

int	check_numbers(t_data *d, char **arguments, int place)
{
	char	**rgb;

	rgb = NULL;
	if (check_space_colors(arguments) == -1)
		return (ft_error("Invalid format for color arguments\n"));
	if (place == 0)
	{
		if (join_assign_fc_colors(d, arguments) == -1)
			return (-1);
	}
	if (ft_strncmp(arguments[0], "F", 1) == 0)
	{
		if (ft_strlen(arguments[0]) > 1)
			return (ft_error("Error ; Arguments are not correct\n"));
		if (check_format(d->color_f, 0, 0, 0) == -1)
			return (-1);
		rgb = ft_split(d->color_f, ',');
		if (!rgb)
			return (ft_error("Error: malloc failed\n"));
		if (check_for_floor(d, rgb) == -1)
			return (free_env(&rgb), -1);
	}
	if (check_numbers2(d, arguments) == -1)
		return (-1);
	return (free_env(&rgb), 0);
}
