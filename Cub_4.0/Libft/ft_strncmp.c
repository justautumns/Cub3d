/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:33:26 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/06 20:33:28 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 != '\0' || *s2 != '\0') && (n > 0))
	{
		if ((unsigned char)*s1 - (unsigned char)*s2 < 0)
			return (-1);
		if ((unsigned char)*s1 - (unsigned char)*s2 > 0)
			return (1);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
/*
int	main()
{
	printf("%d\n", strncmp("THis", "This", 2));
	printf("%d\n", ft_strncmp("THis", "This", 2));
}*/
/*
int	main()
{
	char *s1 = "MZIRIBMZIRIBMZE123";
    char *s2 = "MZIRIBMZE";
    size_t max = strlen(s2);
    int	i1 = strncmp(s1, s2, max);
    int	i2 = ft_strncmp(s1, s2, max);

	printf("Original: %d\n", i1);
	printf("Mine    : %d\n", i2);
}*/