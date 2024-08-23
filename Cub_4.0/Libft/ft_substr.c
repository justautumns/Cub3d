/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:38:11 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/13 13:38:13 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	char			*str;
	unsigned int	temp_start;
	size_t			act_len;

	act_len = 0;
	if (start >= ft_strlen(s) || !len)
		return (ft_strdup(""));
	temp_start = start;
	while (s[temp_start++] != '\0')
		act_len++;
	if (len <= act_len)
		sub = malloc(len + 1);
	if (len > act_len)
		sub = malloc(act_len + 1);
	if (!sub)
		return (0);
	str = sub;
	s += start;
	while (len-- && *s)
		*str++ = *s++;
	*str = '\0';
	return (sub);
}
/*
int	main()
{
	char	*result;

	result = ft_substr("Testing", 6, 0);
	printf("%s\n", result);	
}*/
