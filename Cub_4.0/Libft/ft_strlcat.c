/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:36:48 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/06 15:36:50 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <bsd/string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	limit;

	dlen = 0;
	slen = 0;
	while (*dest != '\0')
	{
		dlen++;
		dest++;
	}
	limit = (size - dlen - 1);
	while (src[slen] != '\0')
		slen++;
	while (*src != '\0' && limit > 0 && size > dlen)
	{
		*dest = *src;
		dest++;
		src++;
		limit--;
	}
	*dest = '\0';
	if (size < dlen)
		return (size + slen);
	return (dlen + slen);
}
/*
int	main()
{
	char	src[20] = "ing";
	char	dest[20] = "Test";
	char	src2[20] = "ing";
	char	dest2[20] = "Test";

	printf("%zu\n", strlcat(dest, src, 8));
	strlcat(dest, src, 8);
	printf("%s\n", dest);
	printf("\n");
	printf("%zu\n", ft_strlcat(dest2, src2, 8));
	ft_strlcat(dest2, src2, 8);
	printf("%s\n", dest2);
}*/
