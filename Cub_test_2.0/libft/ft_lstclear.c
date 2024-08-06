/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:14:32 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/15 13:20:58 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*first;
	t_list	*last;

	if (!lst || !del)
		return ;
	first = *lst;
	while (first)
	{
		last = first->next;
		del(first->content);
		free(first);
		first = last;
	}
	*lst = NULL;
}
