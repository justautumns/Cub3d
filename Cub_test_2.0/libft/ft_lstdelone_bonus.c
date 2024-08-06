/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:30:45 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/15 12:55:57 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*yeni;

	yeni = lst;
	if (!yeni || !del)
		return ;
	if (yeni != NULL)
	{
		if (del != NULL)
			del(yeni->content);
		free(yeni);
	}
}
