/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:59:29 by mtrojano          #+#    #+#             */
/*   Updated: 2023/09/12 15:59:31 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
/*
int	main()
{
	int	*nums;

	for (int i = 0; i < 100; i++)
	{
		nums = malloc(1000000 * sizeof(int));
		for (int j = 0; j < 1000000; j++)
			nums[j] = 564782528;
		free(nums);
	}
	
	char	*arr;

	arr = ft_calloc(50, sizeof(int));
	//strcpy(arr, "abcdefghijklmnop");
	for (int x = 0; x < 10; x++)
		arr[x] = x;

	for (int x = 0; x < 20; x++)
		printf("%d", arr[x]);
	free(arr);
}*/
