/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:20:30 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/31 19:29:07 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;
	char	*ret_dup;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
		len++;
	ret_dup = malloc((len + 1) * sizeof(char));
	if (!ret_dup)
		return (0);
	dup = ret_dup;
	while (*s)
		*dup++ = *s++;
	*dup = '\0';
	return (ret_dup);
}
/*
int	main()
{
	char	*str = "Testing";
	char	*str2 = ft_strdup(str);

	printf("Original:  %s\n", str);
	printf("Duplicate: %s\n", str2);
}*/
