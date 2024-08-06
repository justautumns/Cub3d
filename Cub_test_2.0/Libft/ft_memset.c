/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:34:26 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/11 15:34:29 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	int		pos;
	char	*temp;

	temp = s;
	pos = 0;
	while (n > 0)
	{
		temp[pos] = c;
		pos++;
		n--;
	}
	return (s);
}
/*
int	main()
{
	char	str[50] = "Blah blah Something";
	char	str2[50] = "Blah blah Something";

	memset(str, '7', 4);
	ft_memset(str2, '7', 4);
	printf("%s\n", str);
	printf("%s\n", str2);
}*/
