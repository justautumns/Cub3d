/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:43:46 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/17 00:32:36 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	counter(char const *s, char c)
{
	int	words_count;
	int	last;

	words_count = 0;
	last = ft_strlen(s) - 1;
	if (*s != '\0')
		if (s[last] != c)
			words_count++;
	while (*s && c != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		if (ft_strchr(s, c) != 0)
		{
			words_count++;
			s = ft_strchr(s, c);
		}
		s++;
	}
	return (words_count);
}

static void	free_all(int x, char **strings)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

static int	pos_len(char const *s, char c, int option)
{
	int	len;
	int	pos;

	len = 0;
	pos = 0;
	if (s[pos] == '\0')
		return (0);
	while (s[pos] == c)
		pos++;
	while (s[pos] != '\0' && s[pos] != c)
	{
		len++;
		pos++;
	}
	if (option == 1)
		return (len);
	return (pos);
}

static void	create(char const *s, char **strings, int x, char c)
{
	int	y;
	int	start;
	int	len;
	int	pos;

	y = 0;
	len = pos_len(s, c, 1);
	pos = pos_len(s, c, 0);
	start = pos - len;
	while (len > 0)
	{
		strings[x][y] = s[start];
		y++;
		start++;
		len--;
	}
	strings[x][y] = '\0';
}

char	**ft_split(char const *s, char c)
{
	int		words_count;
	int		x;
	char	**strings;

	x = 0;
	if (!s)
		return (NULL);
	words_count = counter(s, c);
	strings = malloc((words_count + 1) * sizeof(char *));
	if (!strings)
		return (0);
	while (x < words_count)
	{
		strings[x] = malloc(pos_len(s, c, 1) + 1);
		if (!strings[x])
		{
			free_all(x, strings);
			return (0);
		}
		create(s, strings, x, c);
		s += pos_len(s, c, 0);
		x++;
	}
	strings[x] = NULL;
	return (strings);
}
/*
int	main()
{
	int	i;
	char	**arr;

	i = 0;
	arr = ft_split("  So this is a test.  ", ' ');
	printf("Words count = %d\n", counter("  So this is a test.  ", ' '));
	while (i < 5)
	{
		printf("%s\n", arr[i]);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}*/

// int	main()
// {
// 	//char	*str = "";

// 	ft_split("", 'z');
// }