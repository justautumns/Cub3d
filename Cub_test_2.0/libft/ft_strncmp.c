/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:29:19 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/08 21:24:13 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t k)
{
	size_t	m;

	if (k == 0)
		return (0);
	m = 0;
	while (str1[m] == str2[m] && str1[m])
	{
		if (m < (k - 1))
			m++;
		else
			return (0);
	}
	return ((unsigned char)(str1[m]) - (unsigned char)(str2[m]));
}
