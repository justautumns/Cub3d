/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:00:18 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/15 23:23:34 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	pos;

	pos = 0;
	while (s[pos])
	{
		f(pos, &s[pos]);
		pos++;
	}
}
/*
void	func(unsigned int i, char *s)
{
	s[i] = 'A';
}

int	main()
{
	char	str[] = "Hello there!";

	printf("%s\n", str);
	ft_striteri(str, func);
	printf("%s\n",str);
}*/
