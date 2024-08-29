/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:32:33 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/30 00:08:34 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_strlen_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	free_env(char ***env)
{
	int	i;

	i = 0;
	if (!*env)
		return ;
	while ((*env)[i])
	{
		free((*env)[i]);
		i++;
	}
	free(*env);
	*env = NULL;
}

char	**add_to_array(char **arr, char *str)
{
	char	**temp;
	int		size;

	size = 0;
	if (!str)
		return (arr);
	while (arr[size])
		size++;
	temp = malloc((size + 2) * sizeof(char *));
	if (!temp)
		return (free_env(&arr), NULL);
	size = 0;
	while (arr[size])
	{
		temp[size] = ft_strdup(arr[size]);
		if (!temp[size])
			return (free_env(&arr), free_env(&temp), NULL);
		size++;
	}
	temp[size] = ft_strdup(str);
	if (!temp[size])
		return (free_env(&arr), free_env(&temp), NULL);
	temp[size + 1] = NULL;
	free_env(&arr);
	return (temp);
}

int	get_color_from_rgb(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}
