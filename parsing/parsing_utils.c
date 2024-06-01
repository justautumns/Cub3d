/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:09:16 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/06/01 20:29:21 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int count_tabs(char *line)
{
	int	i;

	i = 0;
	int	count_tabs;
	count_tabs = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			count_tabs++;
		i++;
	}
	if (count_tabs == 0)
		return (0);
	int len = ft_strlen(line);
	int new_len = len + (count_tabs * 4);
	return (new_len);
}

char	*check_tabs(char *line)
{
	char	*tmp;
	int		i;
	int		m;
	int		s;

	tmp = malloc(sizeof(char) * count_tabs(line) + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	m = 0;
	while (line[i])
	{
		s = 4;
		if (line[i] != '\t')
		{
			tmp[m] = line[i];
			m++;
			i++;
		}
		else
		{
			while (s--)
				tmp[m++] = 'c';
			i += 1;
		}
	}
	tmp[m] = '\0';
	return (free(line), tmp);
}
