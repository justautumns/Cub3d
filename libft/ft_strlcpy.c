/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:22:18 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/08 20:30:01 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	m;

	if (!size)
		return (ft_strlen(src));
	m = 0;
	while (src[m] && m < size - 1)
	{
		dest[m] = src[m];
		m++;
	}
	dest[m] = '\0';
	return (ft_strlen(src));
}
