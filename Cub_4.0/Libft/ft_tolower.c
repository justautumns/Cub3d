/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:24:41 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/05 20:24:51 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_tolower(int c)
{
	if ((c >= 'A') & (c <= 'Z'))
		c += 32;
	else
		return (c);
	return (c);
}
/*
int	main()
{
	printf("%c\n", tolower('W'));
	printf("%c\n", tolower('p'));
	printf("%c\n", tolower('7'));
	printf("\n");
	printf("%c\n", ft_tolower('W'));
	printf("%c\n", ft_tolower('p'));
	printf("%c\n", ft_tolower('7'));
}*/
