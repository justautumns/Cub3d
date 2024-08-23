/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_tex_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 07:18:47 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/23 07:21:44 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
