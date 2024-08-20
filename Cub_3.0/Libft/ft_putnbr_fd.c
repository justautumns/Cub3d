/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:46:00 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/16 23:10:59 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	convert(int n, int len, int fd)
{
	int		div;
	char	digit;

	div = 1;
	len -= 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (len >= 1)
		while (len--)
			div *= 10;
	while (div > 0)
	{
		digit = n / div + 48;
		write(fd, &digit, 1);
		n = n % div;
		div /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
		convert(n, get_len(n), fd);
}
/*
int	main()
{
	ft_putnbr_fd(-21474836, 1);
}*/
