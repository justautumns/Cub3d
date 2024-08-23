/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:51:14 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/11 15:51:16 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = s;
	while (n > 0)
	{
		*temp = '\0';
		temp++;
		n--;
	}
}
/*
int	main()
{
	int	i;
	int	x;
	char	str[50] = "Something blah blah";
	char	str2[50] = "Something blah blah";

	i = 0;
	x = 0;
	bzero(str, 4);
	ft_bzero(str2, 4);
	while (i < 50)
	{
		printf("%c -- %d\n", str[i], x);
		i++;
		x++;
	}
	i = 0;
	x = 0;
	printf("\n\n");
	while (i < 50)
	{
		printf("%c -- %d\n", str2[i], x);
		i++;
		x++;
	}
}*/
