/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:39:51 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/09 12:56:02 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	m;
	size_t	k;

	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	m = ft_strlen(dest);
	k = 0;
	while (src[k] && m < size - 1)
	{
		dest[m] = src[k];
		m++;
		k++;
	}
	dest[m] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[k]));
}
