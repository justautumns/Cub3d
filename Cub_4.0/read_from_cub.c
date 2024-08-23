/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:16:20 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/08/23 22:52:33 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub.h"

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

int	check_line(char *line, t_data *d)
{
	if (line && ft_strncmp(line, "Error", 5) == 0)
		return (-1);
	if (line && ft_strncmp(line, "\n", 1) != 0)
	{
		if (just_spaces(line) == 0)
			return (ft_error("There can't be spaces between arguments\n"));
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
		if (check_before_map(map_line) == -1)
			return (free(map_line), ft_error("Too many elements in map\n"));
		if (map_line[0] != '\n')
		{
			d->map = add_to_array(d->map, map_line);
			if (!d->map)
				return (free(map_line), ft_error("Error: malloc failed\n"));
		}
		free(map_line);
		map_line = get_next_line(fd);
		if (map_line && ft_strncmp(map_line, "Error", 5) == 0)
			return (ft_error("Error: malloc failed\n"));
	}
	return (free(map_line), 0);
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
		return (free(line), finish_reading(fd), -1);
	free(line);
	get_map_size(d);
	return (0);
}
