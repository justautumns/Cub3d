/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:09:06 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/08 20:12:31 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *a, const void *b, size_t k)
{
	size_t	m;

	m = 0;
	while (m < k)
	{
		if (((unsigned char *)a)[m] != ((unsigned char *)b)[m])
			return (((unsigned char *)a)[m] - ((unsigned char *)b)[m]);
		m++;
	}
	return (0);
}
