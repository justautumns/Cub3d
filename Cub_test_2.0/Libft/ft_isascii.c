/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:20:55 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/05 14:20:57 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int arg)
{
	if ((arg >= 0) & (arg <= 127))
		return (1);
	return (0);
}
/*
int	main()
{
	printf("%d\n", isascii(127));
	printf("%d\n", ft_isascii(127));
}*/
