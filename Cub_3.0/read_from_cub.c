/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:16:20 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/08/20 18:45:50 by mtrojano         ###   ########.fr       */
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

int	compare_check(char *name)
{
	if (ft_strncmp(name, "F", 1) == 0)
		return (1);
	if (ft_strncmp(name, "C", 1) == 0)
		return (1);
	if (ft_strncmp(name, "SO", 2) == 0)
		return (2);
	if (ft_strncmp(name, "NO", 2) == 0)
		return (2);
	if (ft_strncmp(name, "WE", 2) == 0)
		return (2);
	if (ft_strncmp(name, "EA", 2) == 0)
		return (2);
	return (-1);
}


int	assign_fc(t_data *d, char *name, char *all_values)
{
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

	if (place == 0) // because of checking duplication (this message was shown when it shouldnt -> return (ft_error("Cannot have more than one F\n"));)
	{
		if (join_assign_fc_colors(d, arguments) == -1)
			return (-1);
	}
	if (ft_strncmp(arguments[0], "F", 1) == 0)
	{
		rgb = ft_split(d->color_f, ',');
		if (!rgb)
			return (ft_error("Error: malloc failed\n"));
		if (check_for_floor(d, rgb) == -1)
			return (free_env(&rgb), -1);
	}
	if (ft_strncmp(arguments[0], "C", 1) == 0)
	{
		rgb = ft_split(d->color_c, ',');
		if (!rgb)
			return (ft_error("Error: malloc failed\n"));
		if (check_for_ceiling(d, rgb) == -1)
			return (free_env(&rgb), -1);
	}
	free_env(&rgb);
	return (0);
}

int	validate(t_data *d, char **arguments)
{
	if (compare_check(arguments[0]) == -1)
		return (ft_error("Error: Invalid arguments in map\n"));
	if (ft_strncmp(arguments[0], "F", 1) == 0)
	{
		if (d->color_f)
			return (ft_error("Cannot have more than one F\n"));
		d->color_f = ft_strdup(arguments[1]);
		if (!d->color_f)
			return (ft_error("Error: malloc failed\n"));
		return (check_numbers(d, arguments, 1));
	}
	if (ft_strncmp(arguments[0], "C", 1) == 0)
	{
		if (d->color_c)
			return (ft_error("Cannot have more than one C\n"));
		d->color_c = ft_strdup(arguments[1]);
		if (!d->color_c)
			return (ft_error("Error: malloc failed\n"));
		return (check_numbers(d, arguments, 1));
	}
	if (texture_check(arguments[1]) == -1)
		return (ft_error("Error: Texture extension not valid\n"));
	if (check_directions(d, arguments[0], arguments[1]) == -1)
		return (-1);
	return (0);
}

int	arg_validation_map(t_data *d, char *str)
{
	char	**arguments;

	arguments = ft_split(str, ' ');
	if (!arguments)
		return (-1);
	if (!arguments[1])
		return (free_env(&arguments),
			ft_error("Error: Invalid arguments in map\n"));
	if (arguments[2] && compare_check(arguments[0]) != 1)
		return (free_env(&arguments),
			ft_error("Error: Invalid arguments in map\n"));
	else if (arguments[2] && compare_check(arguments[0]) == 1)
	{
		if (check_numbers(d, arguments, 0) == -1)
			return (free_env(&arguments), -1);
	}
	else if (validate(d, arguments) == -1)
		return (free_env(&arguments), -1);
	free_env(&arguments);
	return (0);
}

bool	have_all_info(t_data *d)
{
	if (d->tex->no_path && d->tex->so_path
		&& d->tex->we_path && d->tex->ea_path
		&& d->color_c && d->color_f)
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
		return (-1);
	if (line && ft_strncmp(line, "\n", 1) != 0)
	{
		//need to check if line is only spaces for example (that is wrong -> return (-1))
		if (arg_validation_map(d, line) == -1)
			return (-1);
	}
	return (0);
}

int	get_actual_map(t_data *d, int fd, char *line)
{
	char	*map_line;

	if (!line)
		return (ft_error("Error: Map incomplete\n"));
	if (line && ft_strncmp(line, "Error", 5) == 0)
		return (ft_error("Error: malloc failed\n"));
	map_line = ft_strdup(line);
	if (!map_line)
		return (ft_error("Error: malloc failed\n"));
	while (map_line)
	{
		d->map = add_to_array(d->map, map_line);
		if (!d->map)
			return (free(map_line), ft_error("Error: malloc failed\n"));
		free(map_line);
		map_line = get_next_line(fd);
		if (map_line && ft_strncmp(map_line, "Error", 5) == 0)
			return (ft_error("Error: malloc failed\n"));
	}
	free(map_line);
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
	while (line && have_all_info(d) == false)
	{
		if (check_line(line, d) == -1)
		{
			free(line);
			finish_reading(fd);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (get_actual_map(d, fd, line) == -1)
		return (free(line), -1);
	free(line);
	get_map_size(d);
	return (0);
}
