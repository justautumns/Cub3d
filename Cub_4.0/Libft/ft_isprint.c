/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:41:02 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/05 14:41:04 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int arg)
{
	if ((arg >= 32) & (arg <= 126))
		return (16384);
	return (0);
}
/*
int	main()
{
	printf("%d\n", isprint(129));
	printf("%d\n", ft_isprint(129));
}*/
