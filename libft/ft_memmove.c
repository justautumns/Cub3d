/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:10:54 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/11 21:23:37 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t k)
{
	unsigned char	*a;
	unsigned char	*b;

	a = dest;
	b = (unsigned char *)src;
	if (dest < src)
	{
		return (ft_memcpy(dest, src, k));
	}
	if (dest > src)
	{
		while (k--)
		{
			a[k] = b[k];
		}
	}
	return (dest);
}
