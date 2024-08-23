/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:13:42 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/13 17:13:44 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*joined;
	char	*temp;

	len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(len + 1);
	if (!joined)
		return (0);
	temp = joined;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (joined);
}
/*
int	main()
{
	printf("%s\n", ft_strjoin("This is", " a test."));
}*/
