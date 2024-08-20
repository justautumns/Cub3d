/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:13:45 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/06 13:13:47 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <bsd/string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	while (*src != '\0' && size > 1)
	{
		*dest = *src;
		src++;
		dest++;
		size--;
	}
	*dest = '\0';
	return (len);
}
/*
int	main()
{
	char    str1[20] = "Test";
	char    str2[20];
	char    str3[20] = "Test";
	char    str4[20];

	printf("%zu\n", strlcpy(str2, str1, 0));
	strlcpy(str2, str1, 0);
	printf("Original: %s\n", str2);
	printf("\n");
	printf("%zu\n", ft_strlcpy(str4, str3, 0));
	ft_strlcpy(str4, str3, 0);
	printf("Mine:     %s\n", str4);
}*/
