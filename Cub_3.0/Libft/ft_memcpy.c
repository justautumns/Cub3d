/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:43:16 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/11 15:43:18 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*source;

	dest = dst;
	source = src;
	if (!dst && !src)
		return (dst + 1);
	while (n--)
		*dest++ = *source++;
	return (dst);
}
/*
int	main()
{
	char src[] = "test basic du memcpy !";
	char buff1[22];
    //char *r1 = memcpy(buff1, src, 22);
    char *r2 = ft_memcpy(buff1, src, 22);

	//printf("Original: %s\n", r1);
	printf("Mine    : %s\n", r2);
}*/
/*
int	main()
{
	char	dest[3];
	char	dest2[3];
	char	src[] = "zzz";

	memcpy(dest, src, 3);
	printf("%s\n", dest);
	ft_memcpy(dest2, src, 3);
	printf("%s\n", dest2);
}*/