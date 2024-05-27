/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:23:46 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/06 18:32:09 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int t, size_t k)
{
	size_t	m;

	m = 0;
	while (m < k)
	{
		((unsigned char *)str)[m] = t;
		m++;
	}
	return (str);
}
