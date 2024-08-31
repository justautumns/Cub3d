/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:46:00 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/05 13:59:12 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int num)
{
	if ((num >= 48) & (num <= 57))
		return (2048);
	return (0);
}
/*
int	main()
{
	printf("%d\n", isdigit('7'));
	printf("%d", ft_isdigit('7'));
}*/