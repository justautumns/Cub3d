/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:20:31 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/14 21:38:49 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				m;
	const unsigned char	*p;

	m = 0;
	if (s == NULL)
	{
		((char *)s)[1] = 'c';
	}
	p = (const unsigned char *)s;
	while (m < n)
	{
		if (p[m] == (unsigned char)c)
			return ((void *)&p[m]);
		m++;
	}
	return (NULL);
}
