/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 07:22:03 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/23 23:02:46 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//need to check -> len of arguments[0]; more than 1 -> error (THIS IS DONE AND TESTED, LINE 105 and 121 one new function)!! 
//; (example: "F," <- wrong same for "NO,") 
//and then enough if check d->colors_f and d->colors_c if there are only 2 commas and not after each other.
//or in assign_fc() -> then len of name and commas in all_values. (I HAVE TO LEAVE NOW GONNA DO IT TOMORROW)

void	print_arr(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		printf("'%s'", arr[i]);
		i++;
	}
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

int	check_numbers2(t_data *d, char **arguments, char **rgb)
{
	if (ft_strncmp(arguments[0], "C", 1) == 0)
	{
		if (ft_strlen(arguments[0]) > 1)
			return (-1);
		rgb = ft_split(d->color_c, ',');
		if (!rgb)
			return (ft_error("Error: malloc failed\n"));
		if (check_for_ceiling(d, rgb) == -1)
			return (free_env(&rgb), -1);
	}
	return (0);
}

int	check_numbers(t_data *d, char **arguments, int place)
{
	char	**rgb;

	rgb = NULL;
	if (place == 0)
	{
		if (join_assign_fc_colors(d, arguments) == -1)
			return (-1);
	}
	if (ft_strncmp(arguments[0], "F", 1) == 0)
	{
		if (ft_strlen(arguments[0]) > 1)
			return (ft_error("Error ; Arguments are not correct\n"));
		rgb = ft_split(d->color_f, ',');
		if (!rgb)
			return (ft_error("Error: malloc failed\n"));
		if (check_for_floor(d, rgb) == -1)
			return (free_env(&rgb), -1);
	}
	if (check_numbers2(d, arguments, rgb) == -1)
		return(ft_error("Error ; Arguments are not correct\n"));
	free_env(&rgb);
	return (0);
}
