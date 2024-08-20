/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:58:31 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/06 18:58:33 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	pos;
	int		last_pos;
	int		found;

	pos = 0;
	last_pos = 0;
	found = 0;
	while (pos < ft_strlen(str))
	{
		if (str[pos] == (unsigned char)c)
		{
			last_pos = pos;
			found = 1;
		}
		pos++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str + pos);
	if (found == 1)
		return ((char *)str + last_pos);
	return (0);
}
/*
int	main()
{
	printf("Original: %s\n", strrchr("blah.bl.ah.That was the last dot!", '.'));
	printf("Mine:     %s\n", ft_strrchr("blah.bl.ah.That was the last dot!", '.'));
}*/