/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:37:43 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/11 17:37:45 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;

	str = s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		n--;
		str++;
	}
	return (0);
}
/*
int	main()
{
	char	*result;
	char	*result2;

	result = memchr("Something", 't', 9);
	printf("%s\n", result);
	result2 = ft_memchr("Something", 't', 9);
	printf("%s\n", result2);
}*/
