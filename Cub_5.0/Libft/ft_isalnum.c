/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:01:19 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/05 14:01:24 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalnum(int arg)
{
	if ((arg >= 65) & (arg <= 90)
		|| (arg >= 97) & (arg <= 122)
		|| (arg >= 48) & (arg <= 57))
		return (8);
	return (0);
}
/*
int	main()
{
	printf("%d\n", isalnum(70));
	printf("%d\n", ft_isalnum(70));
}*/
