/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:12:33 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/09 20:42:51 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			boyut1;
	size_t			boyut2;
	unsigned int	m;
	unsigned int	k;
	char			*ptr;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	boyut1 = ft_strlen(s1);
	boyut2 = ft_strlen(s2);
	m = 0;
	ptr = malloc(sizeof(char) * (boyut1 + boyut2 + 1));
	if (!ptr)
		return (NULL);
	k = 0;
	while (s1[m])
		ptr[m++] = s1[k++];
	k = 0;
	while (s2[k])
		ptr[m++] = s2[k++];
	ptr[m] = '\0';
	return (ptr);
}
