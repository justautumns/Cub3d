/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:42:42 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/14 21:39:25 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	m;
	size_t	little_len;

	if (big == NULL)
	{
		((char *)big)[1] = 'c';
	}
	m = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (little_len > len)
		return (NULL);
	while (m < len && big[m] != '\0')
	{
		if (ft_strncmp(&big[m], little, little_len) == 0)
		{
			if (m + little_len > len)
				return (NULL);
			return ((char *)&big[m]);
		}
		m++;
	}
	return (NULL);
}
