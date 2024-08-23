/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:29:18 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/11 16:29:19 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*source;
	unsigned char		*dst;

	if (!dest && !src)
		return (0);
	source = src;
	dst = dest;
	if (dst <= source)
		while (n--)
			*dst++ = *source++;
	else
	{
		dst += n - 1;
		source += n - 1;
		while (n--)
			*dst-- = *source--;
	}
	return (dest);
}
/*
int	main()
{
	char	dest[4] = "123";
	char	dest2[4] = "123";

	memmove(dest, dest + 2, 1);
	printf("%s\n", dest);
	ft_memmove(dest2, dest2 + 2, 1);
	printf("%s\n", dest2);
}*/
