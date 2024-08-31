/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:18:37 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/29 18:33:46 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	string(va_list args)
{
	char	*string;
	int		count;

	count = 0;
	string = va_arg(args, char *);
	if (!string)
		return (write(1, "(null)", 6), 6);
	while (*string)
	{
		write(1, string, 1);
		string++;
		count++;
	}
	return (count);
}
