/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:45:50 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/06 18:45:52 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0' && *str != (unsigned char)c)
		str++;
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (0);
}
/*
int	main()
{
	printf("Original: %s\n", 
	strchr("blahblah.This comes after the dot.", '.'));
	printf("Mine:     %s\n", 
	ft_strchr("blahblah.This comes after the dot.", '.'));
}*/
