/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:16:13 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/05 20:16:15 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_toupper(int c)
{
	if ((c >= 'a') & (c <= 'z'))
		c -= 32;
	else
		return (c);
	return (c);
}
/*
int	main()
{
	printf("%c\n", toupper('t'));
	printf("%c\n", toupper('R'));
	printf("%c\n", toupper('6'));
	printf("\n");
	printf("%c\n", ft_toupper('t'));
	printf("%c\n", ft_toupper('R'));
	printf("%c\n", ft_toupper('6'));
}*/
