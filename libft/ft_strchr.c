/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:02:31 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/16 16:42:01 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int i)
{
	while (*str != '\0' && *str != (unsigned char)i)
	{
		str++;
	}
	if (*str == (unsigned char)i)
	{
		return ((char *)str);
	}
	return (0);
}
/*
int	main(void)
{
	char *str = "blab//lablal.hkrm";
	const char k = '/';

	printf("%s\n", ft_strchr(str, k));
	printf("%s\n", strchr(str,k));
}*/
