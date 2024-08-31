/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:07:53 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/07 14:07:55 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <bsd/string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char		*ret;
	size_t		little_len;

	ret = (char *)big;
	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	while (*big != '\0' && len >= little_len)
	{
		if (*little == *big && ft_strncmp(little, big, little_len) == 0)
		{
			ret = (char *)big;
			return (ret);
		}
		big++;
		len--;
	}
	return (0);
}
/*
int	main()
{
	char *big = "abcdef";
    char *little = "abcdefghijklmnop";
    size_t max = strlen(big);
    char *s1 = strnstr(big, little, max);
    char *s2 = ft_strnstr(big, little, max);

	printf("Original: %s\n", s1);
	printf("Mine    : %s\n", s2);
}*/
/*
int	main()
{
	char *s1 = "MZIRIBMZIRIBMZE123";
    char *s2 = "";
    size_t max = 0;
    char *i1 = strnstr(s1, s2, max);
    char *i2 = ft_strnstr(s1, s2, max);

	printf("Original: %s\n", i1);
	printf("Mine    : %s\n", i2);
}*/
/*
int	main()
{
	printf("%s\n", strnstr("this", "this Let's search.", 5));
	//printf("%s\n", ft_strnstr("this", "this Let's search.", 4));
}*/
/*
int	main()
{
	char *s1 = "see FF your FF return FF now FF";
    char *s2 = "FF";
    size_t max = strlen(s1);
    char *i1 = strnstr(s1, s2, max);
    char *i2 = ft_strnstr(s1, s2, max);

	printf("Original: %s\n", i1);
	printf("Mine    : %s\n", i2);
}*/

/*{
	char		*ret;
	size_t		little_len;

	ret = (char *)big;
	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	while (*big != '\0' && len > 0)
	{
		if ((*little == *big) && (little_len <= len))
		{
			if (ft_strncmp(little, big, little_len) == 0)
			{
				ret = (char *)big;
				return (ret);
			}
		}
		else
		{
			big++;
			len--;
		}
	}
	return (0);
}*/

/*{
	int		pos;
	char	*ret;

	pos = 0;
	ret = (char *)big;
	if (*little == '\0')
		return (ret);
	while (*big != '\0' && len > 0)
	{
		if (little[pos] == *big && little[pos] != '\0')
		{
			if (pos == 0)
				ret = (char *)big;
			pos++;
			if (little[pos] == '\0')
				return (ret);
		}
		big++;
		len--;
		if (little[pos] != *big)
			pos = 0;
	}
	return (0);
}*/