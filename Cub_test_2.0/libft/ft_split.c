/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:58:35 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/10 18:58:40 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_error(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

static size_t	ft_boyutlar(char const *s, char c)
{
	size_t	i;
	size_t	boyutlar;

	if (!s[0])
		return (0);
	i = 0;
	boyutlar = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			boyutlar++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		boyutlar++;
	return (boyutlar);
}

static void	ft_sonrakikelime(char **kelime2, size_t *kelime2_len, char c)
{
	size_t	i;

	*kelime2 += *kelime2_len;
	*kelime2_len = 0;
	i = 0;
	while (**kelime2 && **kelime2 == c)
		(*kelime2)++;
	while ((*kelime2)[i])
	{
		if ((*kelime2)[i] == c)
			return ;
		(*kelime2_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	*kelime2;
	size_t	kelime2_len;
	size_t	i;

	if (!s)
		return (NULL);
	ptr = (char **)malloc(sizeof(char *) * (ft_boyutlar(s, c) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	kelime2 = (char *)s;
	kelime2_len = 0;
	while (i < ft_boyutlar(s, c))
	{
		ft_sonrakikelime(&kelime2, &kelime2_len, c);
		ptr[i] = (char *)malloc(sizeof(char) * (kelime2_len + 1));
		if (!ptr[i])
			return (ft_malloc_error(ptr));
		ft_strlcpy(ptr[i], kelime2, kelime2_len + 1);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
