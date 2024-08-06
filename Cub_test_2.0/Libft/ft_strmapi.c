/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:46:28 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/15 21:57:29 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	int				len;

	if (!s || !f)
		return (0);
	i = 0;
	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (0);
	while (len > 0)
	{
		str[i] = f(i, s[i]);
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}

/*char	func(unsigned int i, char c)
{
	unsigned int	a;

	c = ft_toupper(c);
	a = 2;
	if (a != 2)
		return (i);
	return (c);
}

int	main()
{
	printf("%s\n", ft_strmapi("Hello!", func));
	printf("%s\n", ft_strmapi_e("Hello!", func));
}*/
