/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:02:48 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/08 19:37:51 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t k)
{
	size_t	m;

	if (!dest && !src)
	{
		return (0);
	}
	m = 0;
	while (m < k)
	{
		((unsigned char *)dest)[m] = ((unsigned char *)src)[m];
		m++;
	}
	return (dest);
}
