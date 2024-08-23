/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:29:01 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/16 22:24:11 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	start_trim(char const *s1, char const *set)
{
	int	pos;
	int	start;

	pos = 0;
	start = 0;
	while (s1[pos])
	{
		if (ft_strchr(set, s1[pos]) != 0)
			start++;
		else
			break ;
		pos++;
	}
	return (start);
}

static int	end_trim(char const *s1, char const *set)
{
	int	pos;
	int	end;

	pos = ft_strlen(s1) - 1;
	end = 0;
	while (pos >= 0)
	{
		if (ft_strchr(set, s1[pos]) != 0)
			end++;
		else
			break ;
		pos--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	char	*ret_trimmed;
	int		len;

	len = ft_strlen(s1) - start_trim(s1, set) - end_trim(s1, set);
	if (len < 0)
		len = 0;
	ret_trimmed = malloc(len + 1);
	if (!ret_trimmed)
		return (0);
	trimmed = ret_trimmed;
	s1 += start_trim(s1, set);
	while (len--)
		*trimmed++ = *s1++;
	*trimmed = '\0';
	return (ret_trimmed);
}
/*
int	main()
{
	printf("%s\n", ft_strtrim("645Test554", "456"));
}*/
