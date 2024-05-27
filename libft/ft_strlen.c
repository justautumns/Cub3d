/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:57:34 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/12/20 13:21:04 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	char str[] = "blaaskfjsfjkahsfkasfhbla";

	printf("%d\n", ft_strlen(str));
	return (0);
}*/
