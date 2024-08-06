/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:24:22 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/04/16 20:46:12 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t k)
{
	unsigned char	*str1;
	unsigned int	m;

	m = 0;
	str1 = (unsigned char *)str;
	if (k == 0)
		return ;
	while (m != k)
	{
		str1[m] = 0;
		m++;
	}
}
