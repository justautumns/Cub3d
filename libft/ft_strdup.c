/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:58:49 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/09 16:43:38 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;

	cpy = (char *) malloc(ft_strlen(s) + 1);
	if (!cpy)
	{
		return (0);
	}
	ft_memcpy(cpy, s, ft_strlen(s) + 1);
	return (cpy);
}
