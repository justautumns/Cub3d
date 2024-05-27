/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:43:50 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/16 16:40:13 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int a)
{
	if (a >= 65 && a <= 90)
	{
		return (1);
	}
	else if (a >= 97 && a <= 122)
	{
		return (1);
	}
	else
		return (0);
}
/*
int	main(void)
{
	char	x;

	x = 'A';
	printf("%d\n", ft_isalpha(x));
	printf("%d\n", isalpha(x));
	return (0);
}*/
